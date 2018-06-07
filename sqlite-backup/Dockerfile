FROM alpine

RUN set -ex; \
  apk add sqlite curl bash tar xz --no-cache; \
  curl https://raw.githubusercontent.com/kadwanev/retry/master/retry -o /usr/local/bin/retry && chmod +x /usr/local/bin/retry;

COPY backup.sh /backup.sh

CMD ntpd -p pool.ntp.org && echo "$CRON_ENTRY retry /backup.sh" | crontab - && crond -f