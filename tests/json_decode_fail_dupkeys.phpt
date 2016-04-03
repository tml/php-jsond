--TEST--
Test json_decode() function : duplicate key error
--SKIPIF--
<?php
if (!extension_loaded("jsond")) {
 	die('skip JSON extension not available in this build');
}
?>
--FILE--
<?php
require_once "bootstrap.inc";

echo "*** Testing json_decode() : duplicate key error ***\n";

echo "\n-- Testing json_decode() function with duplicate keys --\n";
var_dump( $jsond_decode('{"foo":"bar", "foo":"bar"}', true, 512, JSON_DUPKEYS_AS_ERROR), json_last_error_msg() );

echo "\n-- Testing json_decode() function with duplicate keys without fail option flag set --\n";
var_dump( $jsond_decode('{"foo":"bar", "foo":"bar"}', true, 512), json_last_error_msg() );

?>
===Done===
--EXPECTF--
*** Testing %s : duplicate key error ***

-- Testing json_decode() function with duplicate keys --
NULL
string(33) "Duplicate key found when decoding"

-- Testing json_decode() function with duplicate keys without fail option flag set --
array(1) {
  ["foo"]=>
  string(3) "bar"
}
string(8) "No error"
===Done===
