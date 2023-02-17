"use strict";
let x=10; //global
x=100;
x=200;
console.log(x);
var z='z ki value'; //global 

//lexical scope or Block Scope
{
    var a=20;
    let b=200;
    let x=400;
    console.log(a);
    console.log(b);
    console.log(x);
}

console.log(a);
//console.log(b);

function dance(){
  //let x=1000; 
   y='hello';
   var y; //function block global scope
  console.log('the value of from let global scope',x);
  console.log(a); //var
  console.log(y);
}

//var y; => actual global scope


dance();
console.log(x); //global 
console.log(this.x);
console.log(window.x);
console.log(z);
console.log(this.z);
console.log(window.z);
//console.log(y);

if(true){
    let ab = 'donkey';
    var ac = 'pig';
    console.log(ab);
}

//console.log(ab); //Error
console.log(ac);



