const app = require('../view/server');
const superTest = require('supertest');
let request = superTest(app);

describe("sever", () => {
    it("should get respond", (done) => {
        let code = '| :|::| :|:|: ||::: :|:|: :||:: :::|| ::|:| ::||: :|::| ||::: |';
        request
            .post('/barcodetopostcode')
            .type('form')
            .send({code: code})
            .expect(200)
            .end((err, res) => {
                if (err) {
                    done.fail(err);
                }else{
                    done();
                }
            })
    });
});

describe("sever", () => {
    it("should get respond", (done) => {
        let code = '45056-1234';
        request
            .post('/postcodetobarcode')
            .type('form')
            .send({code: code})
            .expect(200)
            .end((err, res) => {
                if (err) {
                    done.fail(err);
                }else{
                    done();
                }
            })
    });
});

