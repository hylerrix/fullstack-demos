'use strict';
class PostCodetoBarcodeTransformer {
    transformToBarcode(postCode) {
        let digits = loadAllDigit();
        let flag = isValidCode(postCode);
        let flag1 = getCodeNumber(postCode);
        let flag2 = isValidCodeLength(flag1);


        if (flag === false) {
            return {error: `输入的邮编只能含有数字和-`, barcode: ``};
        }

        if (flag1 === false) {
            return {error: `输入的邮编中-的位置必须在第六位`, barcode: ``};
        } else {
            let newPostcode = getCodeNumber(postCode);
            let flag2 = isValidCodeLength(newPostcode);
            if (flag2 === false) {
                return {error: `输入的邮编必须是5位或9位数字`, barcode: ``};
            }
        }


        if (flag && flag2 && flag1 != 'error') {
            let cd = calculateCD(flag1);
            let checkedCode = getCompleteCode(flag1, cd);
            return {error: ``, barcode: getBarcode(checkedCode, digits, cd)};
        }
    }
}

function loadAllDigit() {
    return ['||:::', ':::||', '::|:|', '::||:', ':|::|', ':|:|:', ':||::', '|:::|', '|::|:', '|:|::'];
}

function isValidCode(code) {
    return /^[\d-]+$/.test(code);
}

function isValidCodeLength(postCode) {

    return postCode.length === 5 || postCode.length === 10;
}

function getCodeNumber(postCode) {
    if (postCode.indexOf('-') !== -1) {
        if (postCode.indexOf('-') === 5) {
            let splitCode = postCode.split('-');
            return splitCode[0] + splitCode[1];
        } else {
            return false;
        }
    } else {
        return postCode;
    }
}

/*function isValidCodeLength(postCode) {
 return postCode.length === 5 || postCode.length === 9;

 }*/

function calculateCD(codeNumber) {
    let cd = 0;
    let array = codeNumber.split('');
    let sum = array.reduce((a, b) => {
        return parseInt(a) + parseInt(b);
    });

    if (sum % 10 === 0) {
        cd = 0;
    } else {
        cd = 10 - sum % 10;
    }
    return cd;
}


function getCompleteCode(code, cd) {
    return code + cd;
}

function getBarcode(checkedCode, digits, cd) {
    let postCodeArray = checkedCode.split('');
    let barcode = '|';
    let barcodeArray = postCodeArray.map((item) => {
        return digits[item];
    });
    barcode += (barcodeArray.join('') + '|');

    return barcode + '  ' + 'cd is ' + cd;
}

module.exports = PostCodetoBarcodeTransformer;


