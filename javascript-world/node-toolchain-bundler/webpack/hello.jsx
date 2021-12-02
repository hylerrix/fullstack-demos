/**
 * Created by hanyile on 2017/9/12.
 */

import React from 'react';

class Hello extends React.Component {
  constructor () {
    super()
    this.name = "aaas"
  }

  render () {
    return <h1>Hello { this.name }</h1>
  }
}

export default Hello