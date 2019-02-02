#!/usr/bin/env bash
set -ex

readonly REQUIRED_ENV_VARS=(
  "POSTGRES_USER"
  "POSTGRES_PASSWORD"
  "POSTGRES_DB"
  )

for env_var in ${REQUIRED_ENV_VARS[@]}; do
    if [[ -z "${!env_var}" ]]; then
      echo "Error:
      Environment variable '$env_var' not set.
      Make sure you have the following environment variables set:
        ${REQUIRED_ENV_VARS[@]}
      Aborting."
      exit 1
    else
      echo "$env_var set successfully"
    fi
  done

bash ./scripts/setup-db.sh