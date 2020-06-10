<?php
date_default_timezone_set("PRC");
/**
 * 重写和Final
 * 1. 子类中编写跟父类完全一致的方法可以完成对父类方法的重写
 * 2. 对于不想被任何类继承的类可以在class之前添加final关键字
 * 3. 对于不想被子类重写（overwrite, 修改）的方法，可以在方法定义前面添加final关键字
 */

class BaseClass {
   public function test() {
       echo "BaseClass::test() called\n";
   }
   
   public function moreTesting() {
       echo "BaseClass::moreTesting() called\n";
   }
}

class ChildClass extends BaseClass {
  
  // 重写时参数不一定要跟父类完全一致
   public function moreTesting($tmp=null) {
       echo "ChildClass::moreTesting() called\n";
   }
}
// Results in Fatal error: Cannot override final method BaseClass::moreTesting()
$obj = new ChildClass();
$obj->moreTesting();
?>
