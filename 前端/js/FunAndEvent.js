/**
 * @Author: 秦武胜
 * @Date: 2022-11-01 14:59:12
 * @LastEditTime: 2022-11-01 17:01:32
 * @LastEditors: 秦武胜
 * @Description: 
 * @FilePath: \qindao\前端\js\FunAndEvent.js
 */


function myFunctionTest() {
    //window.alert("提示");
    var date = new Date();
    var text = date.getFullYear();
    text += "/" + (date.getMonth() + 1) + "/";
    text += date.getDate();
    console.log(text.toString());
    text = date.toISOString();
    document.getElementById("demo").innerHTML = text;
}

function myPrint() {
    document.getElementById("print").innerHTML = 12 + 34;
}

function myAlert() {

    window.alert("弹窗警告");
}

