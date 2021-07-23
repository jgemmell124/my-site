import React, { Component } from 'react'
import "../styles/SkillBar.css";
import BarFade from './BarFade';

export default class SkillBar extends Component {
        

    
    render() {


        return (

            <div className="skill-bar" style={{"border-color": "white"}}>

                <p className="bar-label">Python</p>
                <div class="container">
                <BarFade tag="py" className='py'></BarFade>
                </div>

                <p className="bar-label">HTML / CSS</p>
                <div class="container" style={{"border-color": "white"}}>
                <BarFade tag="html" ></BarFade>
                </div>
                
                <p className="bar-label">JavaScript</p>
                <div class="container">
                <BarFade tag="js" ></BarFade>
                </div>

                <p className="bar-label">JavaScript</p>
                <div class="container">
                <BarFade tag="java" ></BarFade>
                </div>

                <p className="bar-label">SQL</p>
                <div class="container">
                <BarFade tag="sql" ></BarFade>
                </div>
                
                <p className="bar-label">C++</p>
                <div class="container">
                <BarFade tag="cpp"></BarFade>
                </div>

                <p className="bar-label">Django</p>
                <div class="container">
                <BarFade tag="django"></BarFade>
                </div>

                <p className="bar-label">React.js</p>
                <div class="container">
                <BarFade tag="react"></BarFade>
                </div>



            </div> 
    
        );
    }
}
