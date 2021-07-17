var a = 1+2;
var b = "おはよう";
var comment = ['おはよう','こんにちは','こんばんは'];
var time = [4,12,20];
var now = 13;
var num;
if(time[0]<now||now<=time[1])
{
    document.write(comment[1]);
    num = 1;
} else if(time[1]<now||now<=time[2]) {
    document.write(comment[2]);
    num = 2;
} else {
    document.write(comment[0]);
    num = 0;
}
//document.writeln(a);
//document.writeln(b);
console.log(a);
console.log(b);
console.log(num);