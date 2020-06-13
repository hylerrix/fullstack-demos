import React from 'react';
import { useHistory } from 'react-router-dom';
import logo from '../logo.svg';
import './App.css';

function App() {
  const history = useHistory()

  const toHome = () => {
    history.push('home')
  }

  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
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
        </a>
      </header>
    </div>
  );
}

export default App;
