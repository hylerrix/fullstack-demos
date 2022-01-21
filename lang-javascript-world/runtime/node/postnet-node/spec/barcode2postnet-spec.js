/**
 * Created by hanyile on 16/8/8.
 */
'use strict';

const barcode2postnet = require('../public/javascript/barcode2postnet.js');
const convertRule = require('../public/javascript/convertRule.js');

describe("barcode2postnet", function () {
    it("should transform a barcode into a postnet", function () {
        let input = "||:|:::|:|:|:::|:::||::||::|:|:|";
        let output = barcode2postnet.barcode2postnet(input);
        let expected = 957135;
        expect(output).toEqual(expected);
    });
});

describe("verifyBarccode", function () {
    it("should verify the barcode`s legilty", function () {
        let input = "||:|:::|:|:|:::|:::||::||::|:|:|";
        let output = barcode2postnet.verifyBarcode(input);
        let expected = true;
        expect(output).toEqual(expected);
    });
    it("should verify the barcode`s legilty", function () {
        let input = "|:||::|:|:";
        let output = barcode2postnet.verifyBarcode(input);
        let expected = false;
        expect(output).toEqual(expected);
    });
    it("should verify the barcode`s legilty", function () {
        let input = "|:||::|:|:|";
        let output = barcode2postnet.verifyBarcode(input);
        let expected = false;
        expect(output).toEqual(expected);
    });
});

describe("isLegalchars", function () {
    it("|:| should return true", function () {
        let input = "|:|";
        let expected = true;
        let output = barcode2postnet.isLegalchars(input);
        expect(output).toBe(expected);
    });
    it("|:* should return false", function () {
        let input = "|:*";
        let expected = false;
        let output = barcode2postnet.isLegalchars(input);
        expect(output).toBe(expected);
    });
    it("|:|:: :|:|: should return false", function () {
        let input = "|:|:: :|:|:";
        let expected = false;
        let output = barcode2postnet.isLegalchars(input);
        expect(output).toBe(expected);
    });
});

describe("hasBarcodeFrame", function () {
    it("should have '| ' at the start and have ' |' at the end", function () {
        let input = "|:|";
        let expected = true;
        let output = barcode2postnet.hasBarcodeFrame(input);
        expect(output).toBe(expected);
    });
    it("should have '| ' at the start and have ' |' at the end", function () {
        let input = "|:";
        let expected = false;
        let output = barcode2postnet.hasBarcodeFrame(input);
        expect(output).toBe(expected);
    });
});

describe("isLegalDigit", function () {

    it("should have 32 digit", function () {
        let input = "||:|:::|:|:|:::|:::||::||::|:|:|";
        let expected = true;
        let output = barcode2postnet.isLegalDigit(input);
        expect(output).toBe(expected);
    });
    it("should have 32 digit", function () {
        let input = "|:|:||:|";
        let expected = false;
        let output = barcode2postnet.isLegalDigit(input);
        expect(output).toBe(expected);
    });
    it("should have 52 digit", function () {
        let input = "||:|:::|:|:|:::||:::||:::||:::||:::||:::||:::||:::||";
        let expected = true;
        let output = barcode2postnet.isLegalDigit(input);
        expect(output).toBe(expected);
    });
});

describe("formatBarcode", function () {
    it("should formatt barcode into a array", function () {
        let input = "||:|:::|:|:|:::|:::||::||::|:|:|";
        let expected = ["|:|::",":|:|:","|:::|",":::||","::||:",":|:|:"];
        let output = barcode2postnet.formatBarcode(input);
        expect(output).toEqual(expected);
    });
});

describe("convertBarcode", function () {
    it("should convert barcode from array to a figure", function () {
        let input = ["|:|::",":|:|:","|:::|",":::||","::||:",":|:|:"];
        let expected = [9, 5, 7, 1, 3, 5];
        let argument = convertRule.loadConvertRule();
        let output = barcode2postnet.convertBarcode(input, argument);
        expect(output).toEqual(expected);
    });
});

describe("mosaicPostnet", function () {
    it("should mosaic a number array into a number", function () {
        let input = [9, 5, 7, 1, 3, 5];
        let expected = 957135;
        let output = barcode2postnet.mosaicPostnet(input);
        expect(output).toEqual(expected);
    });
});

describe("verifyPostnetCD", function () {
    it("should verify postnet`s CD to be correct", function () {
        let input = 957135;
        let expected = true;
        let output = barcode2postnet.verifyPostnetCD(input);
        expect(output).toEqual(expected);
    });
});

describe("formPostnet", function () {
    it("should form the postnet with '-'", function () {
        let input = 957135;
        let expected = 957135;
        let output = barcode2postnet.formPostnet(input);
        expect(output).toEqual(expected);
    });
    it("should form the postnet with '-'", function () {
        let input = 4505612340;
        let expected = "45056-12340";
        let output = barcode2postnet.formPostnet(input);
        expect(output).toEqual(expected);
    });
});