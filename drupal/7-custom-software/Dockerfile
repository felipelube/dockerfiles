FROM drupal:7-apache

ENV DRUSH_VERSION 8.1.15
ENV PHPREDIS_VERSION 3.1.6

COPY custom.php.inc /tmp/custom.php.inc

RUN set -ex; \
  apt-get update; \
  apt-get install -y \
    ssmtp \
    mysql-client \
    sqlite3;

RUN set -ex; \
  curl -f -L https://github.com/drush-ops/drush/releases/download/$DRUSH_VERSION/drush.phar > drush; \
  curl -f -L https://pecl.php.net/get/redis-$PHPREDIS_VERSION.tgz > redis.tgz; \
  pear install redis.tgz; 

RUN set -ex; \
  rm redis.tgz; \
  rm -rf /var/lib/apt/lists/*; \
  echo "FromLineOverride=YES" >> /etc/ssmtp/ssmtp.conf; \  
  echo "sendmail_path = \"/usr/sbin/ssmtp -t\"" > /usr/local/etc/php/conf.d/mail.ini; \  
  chmod +x drush; \
  cp drush /usr/local/bin; \    
  docker-php-ext-enable redis; \
  docker-php-ext-install pdo_mysql; \
  cp ./sites/default/default.settings.php ./sites/default/settings.php; \
  cat /tmp/custom.php.inc >> ./sites/default/settings.php; \
  rm /tmp/custom.php.inc;