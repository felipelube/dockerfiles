FROM drupal:7-apache

ENV DRUSH_VERSION 8.1.13
ENV PHPREDIS_VERSION 3.1.4

COPY custom.php.inc /tmp/custom.php.inc

RUN set -ex; \
  apt-get update; \
  apt-get install -y \
    mysql-client \
    sqlite3; \
  rm -rf /var/lib/apt/lists/*; \
  curl -f -L https://github.com/drush-ops/drush/releases/download/$DRUSH_VERSION/drush.phar > drush; \
  chmod +x drush; \
  cp drush /usr/local/bin; \
  pecl install redis-$PHPREDIS_VERSION; \
  docker-php-ext-enable redis; \
  docker-php-ext-install pdo_mysql; \
  cp ./sites/default/default.settings.php ./sites/default/settings.php; \
  cat /tmp/custom.php.inc >> ./sites/default/settings.php; \
  rm /tmp/custom.php.inc;