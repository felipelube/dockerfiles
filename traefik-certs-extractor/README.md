# Træfik's acme.json Certificates Extractor
A simple dockerfile for automatically extracting certificates from the [Træfik's](https://traefik.io/) acme.json file into .crt and .key files using the [official contrib script](https://github.com/containous/traefik/blob/master/contrib/scripts/dumpcerts.sh)
and the [Event Notify Test Runner (entr)](http://entrproject.org/).

## How to use
- **Docker-compose**: Simply rename the .env.dist file to .env, set the variables as documented in the file and add the Træfik and other services.
- **Standalone container**: docker run -v /path/to/acme.json:/certs-extractor/acme.json:ro -v /path/to/out/dir/:/certs-extractor/certs/ felubra/traefik-certs-extractor
