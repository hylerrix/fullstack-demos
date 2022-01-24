'use strict'

const React16 = React
const e16 = React16.createElement

console.log('React16', React16)

class LikeButton extends React16.Component {
  constructor(props) {
    super(props)
    this.state = { liked: false }
  }

  render() {
    if (this.state.liked) {
      console.log('React16.version', React16.version)
      return 'You liked this.'
    }

    return e16(
      'button',
      { onClick: () => this.setState({ liked: true }) },
      'Like'
    )
  }
}

const domContainer = document.querySelector('#like_button_container')
ReactDOM.render(e16(LikeButton), domContainer)