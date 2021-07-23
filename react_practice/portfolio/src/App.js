import logo from './logo.svg';
import './App.css';
import Intro from './components/Intro';
import SideBar from './components/SideBar';
import About from './components/About';
import Work from './components/Work';
import Footer from './components/Footer';
import Projects from './components/Projects';

function App() {
  return (
    <div className="App">
      <header className="App-header"/>
      <div id="content">
        <Intro/>
        <About/>
        <Work/>
        <Projects/>
        <Footer/>
      </div>
      <SideBar />
    </div>
  );
}

export default App;
