import React from 'react';
import { useHistory } from 'react-router-dom';
import logo from '../logo.svg';
import './App.css';

const AAA = {
  subscribe: () => {
    console.log('subscribe')
    return true
  },
  unsubscribe: () => {
    console.log('unsubscribe')
    return false
  },
}

const aaa = 6

// 通过显示或不显示此组件，来看看 React.useEffect(() => {}) 的注册、销毁情况
const AppHello = () => {
  // const history = useHistory()
  const [flag, setFlag] = React.useState<boolean>(false)
  const [flag2, setFlag2] = React.useState<boolean>(false)

  if (aaa === 6) {
    console.log('6')
  }

  // React.useEffect(() => {
  //   AAA.subscribe()
  //   setTimeout(() => {
  //     setFlag(true)
  //   }, 1000)
  //   return () => {
  //     AAA.unsubscribe()
  //   }
  // })

  // const toHome = () => {
  //   history.push('home')
  // }

  return <header className="App-header">
    {/* <img src={logo} className="App-logo" alt="logo" />
    <p>
      <button onClick={toHome}>to home</button>
    </p>
    <a
      className="App-link"
      href="https://reactjs.org"
      target="_blank"
      rel="noopener noreferrer"
    >
      Learn React
    </a> */}
  </header>
}

const CountApp = () => {
  // const [count, setCount] = React.useState<any>(async () => {
  //   console.log('initCount...')
  //   const needMoreTime: any = async () => {
  //     const p = new Promise((resolve, reject) => {
  //       setTimeout(() => {
  //         console.log('resolve...')
  //         resolve(1)
  //       }, 3000)
  //     })
  //     return p
  //   }
  //   const initCount = await needMoreTime()
  //   console.log('initCount', initCount)
  //   setCount(initCount)
  // })

  // 测试清除函数
  React.useEffect(() => {
    return () => {
      console.log('cleanup countapp')
    }
  })

  React.useDebugValue('666')

  const [count, setCount] = React.useState<number>(() => {
    let initCount = 1
    for (let i = 1; i < 10; i++) {
      initCount *= i
    }
    return initCount
  })

  return (
    <div>
      <div>
        count: { JSON.stringify(count) }
      </div>
      <div>
        <button onClick={() => { setCount(count + 1) }}>count++</button>
        <button onClick={() => { setTimeout(() => { setCount(count + 1) }, 3000) }}>count++ delay 3s</button>
      </div>
    </div>
  )
}

function App() {
  const [isShow, setIsShow] = React.useState<boolean>(false)

  const toggleShow = (s: boolean) => {
    setIsShow(s)
  }

  return (
    <div className="App">
      <CountApp />
      <button onClick={() => { toggleShow(true) }}>show</button>
      <button onClick={() => { toggleShow(false) }}>hide</button>
      {
        isShow
          ? <AppHello></AppHello>
          : <div>Bey~</div>
      }
    </div>
  );
}

export default App;
