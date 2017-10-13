#!/bin/sh
find ./acme.json | entr ./dumpcerts.sh ./acme.json ./certs