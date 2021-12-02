/**
 * Created by hanyile on 16/8/8.
 */
'use strict';

const convertRule = require('./convertRule.js');

function postnet2barcode (postnet) {
    let tempPostnet = postnet.toString();
    if (!verifyPostnet(tempPostnet)) {
        return false;
    }
    let rule = convertRule.loadConvertRule();
    tempPostnet = omitchars(tempPostnet);
    tempPostnet = generateCD(tempPostnet);
    let splitedPostnet = splitPostnet(tempPostnet);
    let convertedPostnet = convertPostnet(splitedPostnet, rule);
    let mosaicedBarcode = mosaicBarcode(convertedPostnet);
    let barcode = formatBarcode(mosaicedBarcode);
    return barcode;
}

function verifyPostnet(postnet) {
    return (isLegalChars(postnet) && islegalDigit(postnet));
}

function isLegalChars(postnet) {
    let divideFlag = 0;
    for(let i in postnet) {
        if (isNaN(postnet[i])) {
            if (postnet[i] !== '-') {
                return false;
            } else {
                divideFlag++;
                if (divideFlag >= 2) {
                    return false;
                }
            }
        }
    }
    return true;
}

function islegalDigit(postnet) {
    return (postnet.length === 5 || postnet.length === 9 || postnet.length === 10);
}

function omitchars(postnet) {
    postnet = parseInt(postnet.split("-").join(""));
    return postnet;
}

function generateCD(postnet) {
    let sum = 0;
    let temp = postnet.toString();
    for (let i in temp) {
        sum += parseInt(temp[i]);
    }
    let CD = (10 - (sum % 10)) % 10;
    postnet = postnet * 10 + CD;
    return postnet;
}

function splitPostnet (postnet) {
    let splitedPostnet = [];
    let tempPostnet = postnet.toString();
    for (let i in tempPostnet) {
        splitedPostnet.push(parseInt(tempPostnet[i]));
    }
    return splitedPostnet;
}

function convertPostnet(splitedPostnet, rule) {
    let convertedPostnet = [];
    for (let s of splitedPostnet) {
        for (let r of rule) {
            if (s === r.key) {
                convertedPostnet.push(r.value);
                break;
            }
        }
    }
    return convertedPostnet;
}

function mosaicBarcode (convertedPostnet) {
    let mosaicedBarcode = "";
    for (let c of convertedPostnet) {
        mosaicedBarcode += c;
    }
    return mosaicedBarcode;
}

function formatBarcode(mosaicedBarcode) {
    let barcode = "|" + mosaicedBarcode + "|";
    return barcode;
}

module.exports = {
    postnet2barcode: postnet2barcode,
    verifyPostnet: verifyPostnet,
    isLegalChars: isLegalChars,
    islegalDigit: islegalDigit,
    omitchars: omitchars,
    generateCD: generateCD,
    splitPostnet: splitPostnet,
    convertPostnet: convertPostnet,
    mosaicBarcode: mosaicBarcode,
    formatBarcode: formatBarcode
};