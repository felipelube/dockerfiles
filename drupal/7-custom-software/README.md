# Drupal 7 (Apache), com software adicional e configurações customizadas
Este dockerfile, baseado oficial do Drupal 7, habilita adicionalmente os softwares abaixo:
- Drush: para manutenção do site diretamente no container
- [MySQL Client](https://dev.mysql.com/doc/refman/5.7/en/programs-client.html)
- SQlite3
- Extensões PHP:
  - MySQL (pdo_mysql)
  - [PHPRedis](https://github.com/phpredis/phpredis/), instalada via PECL

# Variáveis-ambiente
O container espera que as seguintes variáveis-ambiente sejam definidas, de forma a alterar a 
configuração padrão do Drupal:
- DRUPAL_SITE_URL: (opicional) define explicitamente a URL do site
- MYSQL_DRUPAL_DATABASE: nome do banco de dados MySQL para este site
- MYSQL_DRUPAL_USER_NAME: nome do usuário com acesso ao banco acima
- MYSQL_DRUPAL_USER_PASSWORD: senha do usuário acima
- DRUPAL_DEFAULT_DATABASE_DRIVER: define qual banco será usado por padrão. valores permitidos: 
    sqlite ou mysql. Para SQLite, o arquivo do banco deve estar montado em 
    'sites/default/database/.db.sqlite'. Para MySQL, é necessário um container rodando o MySQL na 
    configuração padrão e com o hostname 'mysql'
- DRUPAL_SITE_USE_REDIS: (opicional) sete esta variável para este site usar o Redis como cache 
    backend, requer o módulo redis (https://www.drupal.org/project/redis) instalado no site, além de
    um container rodando o Redis na configuração padrão, sem autenticação, e com o hostname 'redis'
- DRUPAL_SITE_ID: uma string alfanumérica e sem espaços para identifcar o site