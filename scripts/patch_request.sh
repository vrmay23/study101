#!/bin/bash

# -----------------------------------------------------------------------------
# Rebase the current branch on top of upstream's main/master branch,
# then push it to the origin fork using --force-with-lease.
# -----------------------------------------------------------------------------

set -e  # Exit immediately if a command exits with a non-zero status

# Detect the current branch
CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

# Determine whether upstream uses 'main' or 'master'
if git ls-remote --exit-code --heads upstream main > /dev/null 2>&1; then
  BASE_BRANCH="main"
elif git ls-remote --exit-code --heads upstream master > /dev/null 2>&1; then
  BASE_BRANCH="master"
else
  echo "Error: Could not find 'main' or 'master' branch in upstream."
  exit 1
fi

echo "Current branch: $CURRENT_BRANCH"
echo "Rebasing onto: upstream/$BASE_BRANCH"

# Fetch the latest changes from upstream
git fetch upstream

# Rebase the current branch onto upstream base branch
git rebase upstream/$BASE_BRANCH

# Push the rebased branch to the origin fork
git push origin "$CURRENT_BRANCH" --force-with-lease

echo "Rebase and push completed successfully."

