# Security Policy

## Supported versions

Security fixes should target the current default branch unless a release maintainer explicitly identifies another supported release.

## Reporting a vulnerability

Do not publish exploitable details in a public issue. Use GitHub's private vulnerability reporting feature for this repository, if enabled. If private reporting is unavailable, contact a maintainer privately through a verified contact method listed on the repository owner's GitHub profile. Include the affected revision, impact, reproduction steps, and mitigations. Do not include real player records, credentials, or other private data.

## Server operators

- Run the server with the least privileges required.
- Restrict inbound traffic to explicitly required ports.
- Keep world/player backups protected from public access.
- Never commit credentials, production data, or local configuration secrets.
- Test updates against a copy of the world before deployment.
