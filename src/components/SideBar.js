import React, { Component } from 'react'
import { Sidenav } from 'rsuite';
import { EmailRounded } from "@material-ui/icons";
import LinkedInIcon from '@material-ui/icons/LinkedIn';
import GitHubIcon from '@material-ui/icons/GitHub';
import "../styles/SideBar.css";
import BarFade from './BarFade';

const isMobile = window.innerWidth < 600;

export default class SideBar extends Component {
    constructor() {
        super();
        this.state = {
            expanded: true,
            activeKey: "1",
        };
    }
    render() {

        const { expanded } = this.state;

        const links = [
            <a href="#intro">/home</a>,
            <a href="#about">/about</a>,
            <a href="#work">/work</a>,
            <a href="#projects">/projects</a>
        ];

        return (
            <div className="sidebar-nav">
                {!isMobile && (
                <Sidenav
                    expanded={expanded}
                    defaultOpenKeys={["3", "4"]}
                    activeKey={this.state.activeKey}
                    onSelect={this.handleSelect}
                    appearance={"subtle"}>
                    <Sidenav.Body>
                    <div className="sidebar-links">
                        {links.map((link, i) => (
                            <div>{link}</div>
                        ))}
                    </div>
                    </Sidenav.Body>
                </Sidenav>
        )}
            <div className="sidebar-logos" href="/">
            <a href="mailto:gemmell.j@northeastern.edu"><EmailRounded/>
            </a>
            <a href="https://github.com/jgemmell124" target="_blank"><GitHubIcon/>
            </a>
            <a href="https://www.linkedin.com/in/johnwgemmell/" target="_blank"><LinkedInIcon/>
            </a>
          </div>
        </div>
        );
    }
}
