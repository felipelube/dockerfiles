FROM alpine:latest

WORKDIR /certs-extractor

ADD https://raw.githubusercontent.com/containous/traefik/master/contrib/scripts/dumpcerts.sh ./dumpcerts.sh
ADD ./entrypoint.sh ./entrypoint.sh

RUN set -ex; \
    apk add --no-cache bash entr jq openssl util-linux; \    
    chmod +x ./dumpcerts.sh; \
    chmod +x ./entrypoint.sh;

CMD ["./entrypoint.sh"]
ENTRYPOINT ["sh"]