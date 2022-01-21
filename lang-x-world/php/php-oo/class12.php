<?php
date_default_timezone_set("PRC");
/**
 * 魔术方法1
 * 1. 当对象被当做String使用时，__tostring()会被自动调用
 * 2. 当对象被当成方法调用时，__invoke()会被自动调用
 */
class MagicTest{
  public function __tostring(){
    return "This is the Class MagicTest.\n";
  }
  public function __invoke($x){
    echo "__invoke called with parameter " . $x . "\n";
  }
}

$obj =  new MagicTest();
echo $obj;
$obj(5);

?>