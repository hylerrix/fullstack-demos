'use strict';
class BarcodetoPostCodeTransformer{
    transformToPostCode(barcode) {
        let digits = loadAllDigit();
        let flag = isValidBarcodeDigit(barcode);
        let flag1 = isHasFrame(barcode);
        let flag2 = isValidBarcodeLength(barcode);

        if(flag === false){
            return {error: `输入的条码不能有：和|以外的字符`, postCode: ``};
        }

        if(flag1 === false){
            return {error: `输入的条码必须头部和尾部有| 和 |`, postCode: ``};
        }

        if(flag2 === false){
            return {error: `输入的条码digit的数目必须是6或10`, postCode: ``};
        }

        if (flag && flag1 && flag2) {
            let digitsArray = getDigitsArray(barcode);
            let postCodeArray = changePostCodeArray(digitsArray, digits);
            let codeArray = checkCD(postCodeArray);
            return {error: ``, postCode: getPostCode(codeArray)};
        }
    }

}

function loadAllDigit() {
    return ['||:::', ':::||', '::|:|', '::||:', ':|::|', ':|:|:', ':||::', '|:::|', '|::|:', '|:|::'];
}

function isValidBarcodeDigit(barcode) {
    return /^[\|: ]+$/.test(barcode);
}

function isHasFrame(barcode) {
    console.log(222)
    return barcode.slice(0, 2) === "| " && barcode.slice(-2) === " |";
}

function isValidBarcodeLength(barcode) {
    let array1 = barcode.slice(2, -2).split(" ");
    return array1.length === 6 || array1.length === 10;

}

function getDigitsArray(barcode) {
    return barcode.slice(2, -2).split(' ');
}


function changePostCodeArray(array, digits) {
    return array.map((item) => digits.indexOf(item));
}


function checkCD(array) {
    let temp = array.reduce((a, b) => a + b);

    return temp % 10 === 0 ? array : 'error';
}


function getPostCode(codeArray) {
    if (codeArray.length === 10) {
        codeArray.splice(5, 0, '-');
    }

    let postCode = codeArray.join('');
    let code = postCode.substring(0, postCode.length - 1);
    let cd = postCode.substr(postCode.length - 1, 1);
    return code + '  ' + 'cd is ' + cd;
}

module.exports = BarcodetoPostCodeTransformer;