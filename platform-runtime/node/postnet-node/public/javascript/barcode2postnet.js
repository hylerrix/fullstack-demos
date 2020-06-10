/**
 * Created by hanyile on 16/8/8.
 */
'use strict';

const convertRule = require('./convertRule.js');

function barcode2postnet (barcode) {
    if (!(verifyBarcode(barcode))) {
        return false;
    }
    let rule = convertRule.loadConvertRule();
    let formattedInfo = formatBarcode(barcode);
    let convertedBarcode = convertBarcode(formattedInfo, rule);
    let mosaicedPostnet = mosaicPostnet(convertedBarcode);
    if (!verifyPostnetCD(mosaicedPostnet)) {
        return false;
    }
    let postnet = formPostnet(mosaicedPostnet);
    return postnet;
}

function verifyBarcode(barcode) {
    return (isLegalchars(barcode) && hasBarcodeFrame(barcode) && isLegalDigit(barcode)) ?
        true : false
}

function isLegalchars (barcode) {
    for (let i = 0; i< barcode.length; i ++) {
        if (barcode[i] !== "|" && barcode[i] !== ':') {
            return false;
        }
    }
    return true;
}

function hasBarcodeFrame (barcode) {
    return !!(barcode[0] === "|" &&
    barcode[barcode.length - 1] === '|');
}

function isLegalDigit (barcode) {
    return (barcode.length === 5*6+2 || barcode.length === 5*10+2);
}

function formatBarcode (barcode) {
    let formattedBarcode = [];
    for (let i = 1; i < barcode.length - 1; i+=5) {
        let eachString = barcode[i] + barcode[i+1] + barcode[i+2] + barcode[i+3] + barcode[i+4];
        formattedBarcode.push(eachString);
    }
    return formattedBarcode;
}

function convertBarcode (formattedBarcode, rule) {
    let convertedBarcode = [];
    for (let barcode of formattedBarcode) {
        for (let r of rule) {
            if (barcode === r.value) {
                convertedBarcode.push(r.key);
                break;
            }
        }
    }
    return convertedBarcode;
}

function mosaicPostnet (convertedBarcode) {
    let mosaicedPostnet = parseInt(convertedBarcode.join(""));
    return mosaicedPostnet;
}

function verifyPostnetCD(postnet) {
    let CD = postnet % 10;
    let postnetStr = postnet.toString();
    let sum = 0;
    for(let i = 0; i < postnetStr.length - 1; i++) {
        sum += parseInt(postnetStr[i]);
    }
    return ((sum + CD) % 10 === 0);
}

function formPostnet (postnet) {
    let tempPostnet = postnet.toString();
    if (tempPostnet.length === 10) {
        let before = tempPostnet.slice(0,5);
        let after = tempPostnet.slice(5,10);
        postnet = before + "-" + after;
    }
    return postnet;
}

module.exports = {
    barcode2postnet: barcode2postnet,
    verifyBarcode: verifyBarcode,
    isLegalchars: isLegalchars,
    hasBarcodeFrame: hasBarcodeFrame,
    isLegalDigit: isLegalDigit,
    formatBarcode: formatBarcode,
    convertBarcode: convertBarcode,
    mosaicPostnet: mosaicPostnet,
    verifyPostnetCD: verifyPostnetCD,
    formPostnet: formPostnet
};