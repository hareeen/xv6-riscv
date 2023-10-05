#!/bin/zsh

git rev-parse HEAD | xargs git diff-tree -r --no-commit-id --name-only --diff-filter=ACMRT | xargs zip $1
