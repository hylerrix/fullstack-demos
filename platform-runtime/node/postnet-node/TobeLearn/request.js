/**
 * Created by zhangsha on 16-8-2.
 */
const selectView = require('./transformer/action/TransformBarcodeSelectAction')
const request = require('superagent');

function sendRequest(router, cmd) {
    request
        .post(`localhost:4000/${router}`)
        .type('form')
        .send({code: cmd})
        .end((err, res) => {
            if(err || !res.ok){
                console.log('error')
            }else{
                console.log(res.text);
            }
        });
}

module.exports = sendRequest;