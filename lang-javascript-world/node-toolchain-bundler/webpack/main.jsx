/**
 * Created by hanyile on 2017/9/12.
 */

import React from 'react'
import ReactDOM from 'react-dom'

import World from './World.jsx'

import Hello from './Hello.jsx'

ReactDOM.render(
    <World />,
    document.getElementById('world')
);

ReactDOM.render(
    <Hello/>,
    document.getElementById('hello')
);