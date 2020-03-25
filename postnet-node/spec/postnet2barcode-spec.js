/**
 * Created by hanyile on 16/8/8.
 */
'use strict';

const postnet2barcode = require('../public/javascript/postnet2barcode.js');
const convertRule = require('../public/javascript/convertRule.js');


describe("postnet2barcode", function () {
    it("should translate a postnet into a barcode", function () {
        let input = 95713;
        let expected = "||:|:::|:|:|:::|:::||::||::|:|:|";
        let output = postnet2barcode.postnet2barcode(input);
        expect(output).toEqual(expected);
    });
    it("should translate a postnet into a barcode", function () {
        let input = "45056-1234";
        let expected = "|:|::|:|:|:||::::|:|::||:::::||::|:|::||::|::|||:::|";
        let output = postnet2barcode.postnet2barcode(input);
        expect(output).toEqual(expected);
    });
});

describe("verifyPostnet", function () {
    it("should verufy the postnet`s char-legality and digit-legality", function () {
        let input = "95713";
        let expected = true;
        let output = postnet2barcode.verifyPostnet(input);
        expect(output).toEqual(expected);
    });
    it("should verufy the postnet`s char-legality and digit-legality", function () {
        let input = "95741-3098";
        let expected = true;
        let output = postnet2barcode.verifyPostnet(input);
        expect(output).toEqual(expected);
    });
    it("should verufy the postnet`s char-legality and digit-legality", function () {
        let input = "957413";
        let expected = false;
        let output = postnet2barcode.verifyPostnet(input);
        expect(output).toEqual(expected);
    });
});

describe("isLegalChars", function () {
    it("should judge the postnet`s char-legality", function () {
        let input = "95713";
        let expected = true;
        let output = postnet2barcode.isLegalChars(input);
        expect(output).toEqual(expected);
    });
    it("should judge the postnet`s char-legality", function () {
        let input = "95-713";
        let expected = true;
        let output = postnet2barcode.isLegalChars(input);
        expect(output).toEqual(expected);
    });
    it("should judge the postnet`s char-legality", function () {
        let input = "95*713";
        let expected = false;
        let output = postnet2barcode.isLegalChars(input);
        expect(output).toEqual(expected);
    });
    it("should judge the postnet`s char-legality", function () {
        let input = "95-71-3";
        let expected = false;
        let output = postnet2barcode.isLegalChars(input);
        expect(output).toEqual(expected);
    });
});

describe("islegalDigit", function () {
    it("should judge the postnet`s digit-legality", function () {
        let input = "95713";
        let expected = true;
        let output = postnet2barcode.islegalDigit(input);
        expect(output).toEqual(expected);
    });
    it("should judge the postnet`s digit-legality", function () {
        let input = "957413";
        let expected = false;
        let output = postnet2barcode.islegalDigit(input);
        expect(output).toEqual(expected);
    });
    it("should judge the postnet`s digit-legality", function () {
        let input = "95741-3098";
        let expected = true;
        let output = postnet2barcode.islegalDigit(input);
        expect(output).toEqual(expected);
    });
});

describe("omitchars", function () {
    it("should omit the '-' and return a number", function () {
        let input = "95713";
        let output = postnet2barcode.omitchars(input);
        let expected = 95713;
        expect(output).toEqual(expected);
    });
    it("should omit the '-' and return a number", function () {
        let input = "45056-1234";
        let output = postnet2barcode.omitchars(input);
        let expected = 450561234;
        expect(output).toEqual(expected);
    });
});

describe("generateCD", function () {
    it("should count the CD and combine", function () {
        let input = 95713;
        let expected = 957135;
        let output = postnet2barcode.generateCD(input);
        expect(output).toEqual(expected);
    });
    it("should count the CD and combine", function () {
        let input = 450561234;
        let expected = 4505612340;
        let output = postnet2barcode.generateCD(input);
        expect(output).toEqual(expected);
    });
});

describe("splitPostnet", function () {
    it("should split the postnet into an array", function () {
        let input = 957135;
        let expected = [9, 5, 7, 1, 3, 5];
        let output = postnet2barcode.splitPostnet(input);
        expect(output).toEqual(expected);
    });
    it("should split the postnet into an array", function () {
        let input = 4505612340;
        let expected = [4, 5, 0, 5, 6, 1, 2, 3, 4, 0];
        let output = postnet2barcode.splitPostnet(input);
        expect(output).toEqual(expected);
    });
});

describe("convertPostnet", function () {
    it("should convert the postnet into a string array", function () {
        let input = [9, 5, 7, 1, 3, 5];
        let expected = ["|:|::",":|:|:","|:::|",":::||","::||:",":|:|:"];
        let argument = convertRule.loadConvertRule();
        let output = postnet2barcode.convertPostnet(input, argument);
        expect(output).toEqual(expected);
    });
    it("should split the postnet into an array", function () {
        let input = [4, 5, 0, 5, 6, 1, 2, 3, 4, 0];//
        let expected = [":|::|",":|:|:","||:::",":|:|:",":||::",":::||","::|:|","::||:",":|::|","||:::"];
        let argument = convertRule.loadConvertRule();
        let output = postnet2barcode.convertPostnet(input, argument);
        expect(output).toEqual(expected);
    });
});

describe("mosaicBarcode", function () {
    it("should mosaic the barcode arrray into a barcode string", function () {
        let input = ["|:|::",":|:|:","|:::|",":::||","::||:",":|:|:"];
        let expected = "|:|:::|:|:|:::|:::||::||::|:|:";
        let output = postnet2barcode.mosaicBarcode(input);
        expect(output).toEqual(expected);
    });
    it("should mosaic the barcode arrray into a barcode string", function () {
        let input = [":|::|",":|:|:","||:::",":|:|:",":||::",":::||","::|:|","::||:",":|::|","||:::"];
        let expected = ":|::|:|:|:||::::|:|::||:::::||::|:|::||::|::|||:::";
        let output = postnet2barcode.mosaicBarcode(input);
        expect(output).toEqual(expected);
    });
});

describe("formatBarcode", function () {
    it("should format a barcode with a frame", function () {
        let input = "|:|:::|:|:|:::|:::||::||::|:|:";
        let expected = "||:|:::|:|:|:::|:::||::||::|:|:|";
        let output = postnet2barcode.formatBarcode(input);
        expect(output).toEqual(expected);
    });
    it("should format a barcode with a frame", function () {
        let input = ":|::|:|:|:||::::|:|::||:::::||::|:|::||::|::|||:::";
        let expected = "|:|::|:|:|:||::::|:|::||:::::||::|:|::||::|::|||:::|";
        let output = postnet2barcode.formatBarcode(input);
        expect(output).toEqual(expected);
    });
})