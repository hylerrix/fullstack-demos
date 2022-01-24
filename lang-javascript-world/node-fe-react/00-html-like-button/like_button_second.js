'use strict'

const React18 = React
const e18 = React.createElement

console.log('React18', React18)

class LikeButtonSecond extends React18.Component {
  constructor(props) {
    super(props)
    this.state = { liked: false }
  }

  render() {
    if (this.state.liked) {
      console.log('React18.version', React18.version)
      return 'You liked this (2nd).'
    }

    return e18(
      'button',
      { onClick: () => this.setState({ liked: true }) },
      'Like'
    )
  }
}

const domContainerSecond = document.querySelector('#like_button_container_second')
ReactDOM.render(e18(LikeButtonSecond), domContainerSecond)