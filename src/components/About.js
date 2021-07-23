import React, { Component } from 'react'
import "../styles/About.css";
import FadeInSection from './FadeIn';
import "../App.css";
import { EmailRounded } from "@material-ui/icons";
import SkillBar from './SkillBar';                   

class About extends React.Component {
    constructor() {
      super();
      this.state = {
        expanded: true,
        activeKey: "1"
      };
      this.handleSelect = this.handleSelect.bind(this);
    }
    handleSelect(eventKey) {
      this.setState({
        activeKey: eventKey
      });
    }
    render() {
      const one = (
        <p>
          I'm a Computer Engineer/ Computer Science student at <strong>northeastern university </strong>
            in Boston. I am going into my third year.
        </p>
      );
      const two = (
        <p>
          I'm into everything to do with computers, electronics, and software.
          This includes<b> machine learning</b>, <b>AI</b>, <b>web dev</b>,  and{" "}
          <b>cyber security</b>. I enjoy sports, exercising, and the outdoor. I like to go fishing year-round
          and am always looking for my next adventure.
        </p>
      );
      const three = (
        <p>
          <b style={{"font-size": "23px"}}>I am always open for new opurtunites. </b>If you want contact 
          me, send me an email:{" "}
          <a href="mailto:gemmell.j@northeastern.edu">
          gemmell.j@northeastern.edu {" "}
          </a>
          
        </p>
      );
      const desc_items = [one, two, three];
  
      const tech_stack = [
        "RaspberryPi",
        "Arduino",
        "Soldering",
        "Linux",
        "Windows",
        "MacOS"
      ];
  
      const tech_items = tech_stack.map(stack => <li>{stack}</li>);

  
      return (
        <div id="about">
          <FadeInSection>
            <div className="section-header ">
              <span className="section-title">/ about me</span>
            </div>
            <div className="about-content">
              <div className="about-description">
                {desc_items}
                <h4 className="section-title" style={{"font-size": "23px"}}>Skills</h4>
                {"Here are some technologies I have been working with:"}
                <FadeInSection>
                  <SkillBar/>
                </FadeInSection>
                <ul className="tech-stack">
                  {tech_stack.map(function (tech_item, i) {
                    return (
                      <FadeInSection delay={`${i + 1}00ms`}>
                        <li>{tech_item}</li>
                      </FadeInSection>
                    );
                  })}
                </ul>
              </div>
            </div>
          </FadeInSection>
        </div>
      );
    }
  }
  
  export default About;
  