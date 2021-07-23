import React from "react";
import PropTypes from "prop-types";
import { hexToRgb, makeStyles, rgbToHex } from "@material-ui/core/styles";
import Tabs from "@material-ui/core/Tabs";
import Tab from "@material-ui/core/Tab";
import Typography from "@material-ui/core/Typography";
import Box from "@material-ui/core/Box";
import '../styles/Panels.css'
import { color, typography } from "@material-ui/system";
import { keys } from "@material-ui/core/styles/createBreakpoints";
import FadeInSection from "./FadeIn";


function TabPanel(props) {
  const { children, value, index, ...other } = props;

  return (
    <div
      role="tabpanel"
      hidden={value !== index}
      id={`vertical-tabpanel-${index}`}
      aria-labelledby={`vertical-tab-${index}`}
      {...other}
    >
      {value === index && (
          <Box p={3}>
            <Typography>{children}</Typography>
          </Box>
      )}
    </div>
  );
}

TabPanel.propTypes = {
  children: PropTypes.node,
  index: PropTypes.any.isRequired,
  value: PropTypes.any.isRequired
};

function a11yProps(index) {
  return {
    id: `vertical-tab-${index}`,
    "aria-controls": `vertical-tabpanel-${index}`
  };
}

const useStyles = makeStyles((theme) => ({
  root: {
    flexGrow: 1,
    backgroundColor: "transparent",
    display: "flex",
    height: 300
  },
  tabs: {
    borderRight: `1px solid ${theme.palette.divider}`,
    
  }
}));

export default function VerticalTabs() {
  const classes = useStyles();
  const [value, setValue] = React.useState(0);

  const handleChange = (event, newValue) => {
    setValue(newValue);
  };


  return (
    <div className={classes.root}>
      <Tabs
        orientation="vertical"
        variant="centered"
        value={value}
        onChange={handleChange}
        aria-label="Vertical tabs example"
        className={classes.tabs}
        
      >
        <Tab label="Amazon" {...a11yProps(0)} />
        <Tab label={`Dylan & Pete's`} {...a11yProps(1)} />
        <Tab label="Youth Camp" {...a11yProps(2)} />
        <Tab label="VFW Tree Lot" {...a11yProps(3)} />
        <Tab label="Market Basket" {...a11yProps(4)} />
      </Tabs>
      
      {Object.keys(experienceItems).map((key, i) =>

        <TabPanel value={value} index={i}>
        <span className="job-title">{experienceItems[key]["JobTitle"]} @ </span><span className="job-company">{key}</span>
        
        <div className="duration">{experienceItems[key]['Duration']}</div>
        <ul className="job-desc">
          {experienceItems[key]["desc"].map((desc) => {
            return(<FadeInSection>
                      <li>{desc}</li>
                    </FadeInSection>);
          })}
        </ul>
        </TabPanel>
      )}

  
    </div>
  );
}





const experienceItems = {
  "Amazon" : {
      "JobTitle" : "Independent Business Owner",
      "Duration"  : "2020",
      'desc' : [
          "Researched, designed, and sold products on Amazon",
          "Communicated with manufacturers and suppliers around the world",
          "Created multiple ecommerce websites and marketed with PPC advertising. Managed customer service"
      ]
  },
  "Dylan and Pete's Ice Cream" : {
      "JobTitle" : "Truck Driver",
      "Duration" : "Summer 2019",
      "desc": [
          "Operated an Ice Cream truck at corporate and private catering events in Greater Boston area."
      ]
  },
  "Andover Youth Camp" : {
      "JobTitle" : "Youth Coach",
      "Duration" : "Summer 2017-2019",
      "desc": [
          "Assisted in coaching youth players in both football and baseball. Led drills, provided verbal and written scorecard feedback to campers"
      ]
  },
  "VFW Christmas Tree Lot" : {
      "JobTitle" : "Tree Lot Assistant",
      "Duration" : "Fall 2015-2019",
      "desc": [
          "Seasonal job setting up and maintaining Christmas tree lot",
          " Unloaded trucks, organized displays, and assisted customers"
      ]
  },
  "Market Basket" : {
      "JobTitle" : "Bagger and Lot Attendant",
      "Duration" : "2015-2015",
      "desc": [
          "Bagged groceries and provided assistance to customers",
          "Supported cashiers and front-end store employees, collected shopping carts from parking lot"
      ]
  }
};
