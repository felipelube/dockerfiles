/**
 * Configurações customizadas
 *
 * Essas configurações pegam variáveis ambiente setadas no container
 * 
 */

/* Valores hardcoded @todo flexibilizar */
ini_set('max_execution_time', 300); 
ini_set('memory_limit', '256M');
$conf['reverse_proxy'] = TRUE;
$conf['reverse_proxy_addresses'] = array(gethostbyname('proxy'));

if ( getenv( 'DRUPAL_SITE_URL' ) ) {
  $base_url = getenv('DRUPAL_SITE_URL');  // NO trailing slash!
}

$databases['sqlite']['default'] = array(
  'database' => 'sites/default/database/.db.sqlite',
  'driver' => 'sqlite',
  'prefix' => '',
);

$databases['mysql']['default'] = array(
  'driver' => 'mysql', //hardcoded
  'database' => getenv('MYSQL_DRUPAL_DATABASE'),
  'username' => getenv('MYSQL_DRUPAL_USER_NAME'),
  'password' => getenv('MYSQL_DRUPAL_USER_PASSWORD'),
  'host' => 'mysql', //hardcoded
  'prefix' => '',
  'collation' => 'utf8_general_ci',
);

$c_default_database_driver = getenv('DRUPAL_DEFAULT_DATABASE_DRIVER');
$databases['default'] = $databases[$c_default_database_driver];
unset($databases[$c_default_database_driver]);

if ( getenv( 'DRUPAL_SITE_USE_REDIS' ) && getenv( 'DRUPAL_SITE_ID' ) ) {
  // Configurações do módulo Redis
  $conf['redis_client_interface'] = 'PhpRedis';
  $conf['redis_client_host'] = 'redis'; //hardcoded
  // Use semáforos no Redis
  $conf['lock_inc'] = 'sites/all/modules/redis/redis.lock.inc';  
  $conf['path_inc'] = 'sites/all/modules/redis/redis.path.inc';
  // Coloque o cache do Drupal no Redis
  $conf['cache_backends'][] = 'sites/all/modules/redis/redis.autoload.inc';
  $conf['cache_default_class'] = 'Redis_Cache';
  // Um prefixo para cada site Drupal
  $conf['cache_prefix'] = 'drupal_'.getenv('DRUPAL_SITE_ID');
}
