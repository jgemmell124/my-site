import React, { Component } from 'react'
import "../styles/Projects.css"
import FadeInSection from './FadeIn'

export default class Projects extends Component {
    render() {



        return (
            <div id="projects">
                <div className="section-header ">
                    <span className="section-title">/ projects</span>
                </div>
                <div class="grid">
                {Object.keys(projects).map((key, i) => {
                    return (
                        <FadeInSection delay={`${i + 1}00ms`}>
                            <div className="item">
                                <div class="text">
                                    <h3>{key}</h3>
                                    {projects[key]["desc"].map((desc) => {
                                        return(<div className="lang">{desc}</div>);
                                    })}
                                    <span className="lang-txt">
                                        {projects[key]['langs']}
                                    </span>
                                </div>
                            </div>
                        </FadeInSection>
                    );
                })}
                </div>
            </div>
        );
    }
}


const projects = {
    "Maze Generator and Solver " : {
        "langs": ["Java"],
        "desc" : [
            "Created a program to generate a random maze using Krustkal’s algorithm and solve it using breadth-firstand depth-first search."
        ]
    },
    "Digital Accelerometer Reader" : {
        "langs": ["C++"],
        "desc" : [
            "Programmed an fpga board to read x,y, and z values of a Digital Accelerometer Module from memory.",
            "Designed a circuit for the board to translate the values to degrees of board angle and display it on a 7-segment displays of the fpga board."
        ]
    },
    "Automatic Sudoku Solver" : {
        "langs": ["Python, Selenium BS4"],
        "desc" : [
            "Created program to scrape the information of an online sudoku game, solve the board using the Backtracking algorithm, then automatically complete missing spaces on the website."
        ]
    },
    "Thermocouple Data Acquisition System" : {
        "langs": ["C++, MATLAB"],
        "desc" : [
            "Created program to perform numerical analysis of a temperature sensing thermocouple.",
            "Optimized thermocouple design by iterating & plotting different test cases within MATLAB."
        ]
    },
    "IoT HDMI Switcher" : {
        "langs": ["Python, RaspberryPi, Flask"],
        "desc" : [
            "Created Raspberry Pi web server to control output of 3 HDMI inputs from devices on same network."
        ]
    },

};