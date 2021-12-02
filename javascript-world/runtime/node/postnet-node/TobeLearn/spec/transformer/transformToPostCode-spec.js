const toPostCode = require('../../transformer/transformToPostCode');

describe("transformToPostCode", function () {
    let changePostCode;
    beforeEach(()=> {
        changePostCode = new toPostCode();
    });

    it("should return postcode", function () {
        let input = "| :|::| :|:|: ||::: :|:|: :||:: :::|| ::|:| ::||: :|::| ||::: |";
        let result = changePostCode.transformToPostCode(input);
        let postCode = {error: ``, postCode:'45056-1234  cd is 0'};
        expect(result).toEqual(postCode);
    });

    it("barcode has another char", function () {
        let barcode = "| :|&*|";
        let result = changePostCode.transformToPostCode(barcode);
        let expected = {error: `输入的条码不能有：和|以外的字符`, postCode: ``};
        expect(result).toEqual(expected);
    });

    it("barcode not have frame", function () {
        let barcode = "| |: ::| ||";
        let result = changePostCode.transformToPostCode(barcode);
        let expected = {error: `输入的条码必须头部和尾部有| 和 |`, postCode: ``};
        expect(result).toEqual(expected);
    });

    it("digit count not legal", function () {
        let input = '| :|::| :|:|: ||::: :|:|: :||:: :::|| ::|:| ::||: :|::| |';
        let result = changePostCode.transformToPostCode(input);
        let expected = {error: `输入的条码digit的数目必须是6或10| 和 |`, postCode: ``};
        expect(result).toEqual(expected);
    });

});

