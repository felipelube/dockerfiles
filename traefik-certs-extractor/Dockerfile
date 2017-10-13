FROM alpine:latest

WORKDIR /certs-extractor

ADD https://raw.githubusercontent.com/containous/traefik/master/contrib/scripts/dumpcerts.sh ./dumpcerts.sh
ADD ./entrypoint.sh ./entrypoint.sh

RUN set -ex; \
    apk add --no-cache jq openssl entr bash; \    
    chmod +x ./dumpcerts.sh; \
    chmod +x ./entrypoint.sh;

CMD ["./entrypoint.sh"]
ENTRYPOINT ["sh"]