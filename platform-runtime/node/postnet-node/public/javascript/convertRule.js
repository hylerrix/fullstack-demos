/**
 * Created by hanyile on 16/8/8.
 */
'use strict';

function loadConvertRule() {
    return [
        {key: 0, value: "||:::"},
        {key: 1, value: ":::||"},
        {key: 2, value: "::|:|"},
        {key: 3, value: "::||:"},
        {key: 4, value: ":|::|"},
        {key: 5, value: ":|:|:"},
        {key: 6, value: ":||::"},
        {key: 7, value: "|:::|"},
        {key: 8, value: "|::|:"},
        {key: 9, value: "|:|::"}
    ];
}

module.exports = {
    loadConvertRule: loadConvertRule
};