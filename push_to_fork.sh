#!/bin/bash

set -e

echo "==========================================="
echo "=== Commit, rebase and push changes     ==="
echo "==========================================="
echo

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
TARGET_BRANCH="main"

# --- Commit message setup ---
read -p "Add extra commit message (optional): " USER_MSG

SUBMODULE_PATHS=$(git config --file .gitmodules --get-regexp path 2>/dev/null | awk '{ print $2 }')
SUBMODULE_INFO=""

for path in $SUBMODULE_PATHS; do
  if [ -d "$path/.git" ]; then
    HASH=$(cd "$path" && git rev-parse --short HEAD 2>/dev/null)
    SUBMODULE_INFO+="$path@$HASH "
  fi
done

COMMIT_MSG="Update on $(date '+%Y-%m-%d %H:%M:%S')"
[ -n "$SUBMODULE_INFO" ] && COMMIT_MSG+=" | Submodules: $SUBMODULE_INFO"
[ -n "$USER_MSG" ] && COMMIT_MSG+=" - $USER_MSG"

# --- Git add and commit ---
echo "Staging all changes..."
git add -A

if git diff --cached --quiet; then
  echo "Nothing to commit. Working tree is clean."
else
  echo "Committing changes..."
  git commit -m "$COMMIT_MSG"
fi

# --- Rebase from remote ---
echo "Fetching latest from origin..."
git fetch origin

if git rev-parse --verify origin/"$CURRENT_BRANCH" >/dev/null 2>&1; then
  echo "Rebasing $CURRENT_BRANCH on top of origin/$CURRENT_BRANCH..."
  git rebase origin/"$CURRENT_BRANCH"
else
  echo "Branch $CURRENT_BRANCH does not exist on remote. Skipping rebase."
fi

# --- Push current branch ---
echo "Pushing to origin/$CURRENT_BRANCH..."
git push origin "$CURRENT_BRANCH"

# --- Merge into main if not already on it ---
if [ "$CURRENT_BRANCH" != "$TARGET_BRANCH" ]; then
  echo "Switching to $TARGET_BRANCH to integrate changes..."
  git checkout "$TARGET_BRANCH"

  echo "Fetching latest $TARGET_BRANCH..."
  git pull --rebase origin "$TARGET_BRANCH"

  echo "Rebasing $TARGET_BRANCH with $CURRENT_BRANCH..."
  git rebase "$CURRENT_BRANCH"

  echo "Pushing $TARGET_BRANCH..."
  git push origin "$TARGET_BRANCH"

  echo "Switching back to $CURRENT_BRANCH..."
  git checkout "$CURRENT_BRANCH"
fi

echo
echo "Done: Changes committed, rebased and pushed."

