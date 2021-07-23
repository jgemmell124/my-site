
import React, {Component} from 'react';
import VerticalTabs from './TabPanels';
import FadeInSection from './FadeIn';
import '../styles/Work.css'

const jobs = {
    Amazon : {
        "Job Title" : "Independent Business Owner",
        "Duration"  : "2020",
        'desc' : [
            "Researched, designed, and sold products on Amazon",
            "Communicated with manufacturers and suppliers around the world",
            "Created multiple ecommerce websites and marketed with PPC advertising. Managed customer service"
        ]
    },
    Pete : {
        "Job Title" : "Independent Business Owner",
        "Duration" : "Summer 2019",
        "desc": [
            "Operated an Ice Cream truck at corporate and private catering events in Greater Boston area."
        ]
    },
    Camp : {
        "Job Title" : "Youth Coach",
        "Duration" : "Summer 2017-2019",
        "desc": [
            "Assisted in coaching youth players in both football and baseball. Led drills, provided verbal and written scorecard feedback to campers"
        ]
    },
    Tree : {
        "Job Title" : "Tree Lot Assistant",
        "Duration" : "Fall 2015-2019",
        "desc": [
            "Seasonal job setting up and maintaining Christmas tree lot",
            " Unloaded trucks, organized displays, and assisted customers"
        ]
    },
    MB : {
        "Job Title" : "Bagger and Lot Attendant",
        "Duration" : "2015-2015",
        "desc": [
            "Bagged groceries and provided assistance to customers",
            "Supported cashiers and front-end store employees, collected shopping carts from parking lot"
        ]
    }
};


export default class Work extends Component {
    render() {
        return (
            <div id="work">
                <FadeInSection>
                    <div className="section-header ">
                        <span className="section-title">/ work experience</span>
                    </div>
                    <div className="about-content">
                        <VerticalTabs jobs={{jobs}}/>
                    </div>
                </FadeInSection>
            </div>
        )
    }
}
