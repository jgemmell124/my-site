import React, { Component } from 'react'
import { Col, Container } from 'react-bootstrap';
import "../styles/Intro.css";
import "../styles/Typist.css";
import Typist from 'react-typist';
import FadeInSection from './FadeIn';

export default class Intro extends Component {
    render() {
        return (
            <div id="intro">
                <Typist avgTypingDelay={130}>
                    <span className="intro-title">
                        {">> hi, i'm "}<span className="intro-name">
                            {"john"}
                        </span>
                        .
                    </span>
                </Typist>
                <FadeInSection>
                    <div className="intro-subtitle">
                        welcome to my website
                    </div>
                    <div className="intro-desc">
                        i do things with computers
                        <p>
                        scroll down to learn more about what i do
                        </p>
                    </div>
                    
                </FadeInSection>
            </div>
        )
    }
}
