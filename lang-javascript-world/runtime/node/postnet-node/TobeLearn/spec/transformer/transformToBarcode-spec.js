const toBarcode = require('../../transformer/transformToBarcode');

describe("transformToBarcode", function () {
    let changeBarcode;
    beforeEach(() => {
        changeBarcode = new toBarcode();
    });

    it("should return postcode", function () {
        let input = "45056-1234";
        let result = changeBarcode.transformToBarcode(input);
        let barcode = {error: ``, barcode: '|:|::|:|:|:||::::|:|::||:::::||::|:|::||::|::|||:::|  cd is 0'};
        expect(result).toEqual(barcode);
    });

    it("input not have another char", function () {
        let input = "45056-123|";
        let result = changeBarcode.transformToBarcode(input);
        let expected = {error: `输入的邮编只能含有数字和-`, barcode: ``};
        expect(result).toEqual(expected);
    });

    it("- position must correct", function () {
        let input = "450-56234";
        let result = changeBarcode.transformToBarcode(input);
        let expected = {error: `输入的邮编中-的位置必须在第六位`, barcode: ``};
        expect(result).toEqual(expected);
    });

    it("input length must five or nine", function () {
        let input = '4505612347';
        let result = changeBarcode.transformToBarcode(input);
        let expected = {error: `输入的邮编位数必须是5或9`, barcode: ``};
        expect(result).toEqual(expected);
    });

});







