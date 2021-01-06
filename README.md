# Chicago-PD-Brutality-Analysis
A robust analysis of the subjects of crimes and responses by law enforcement in the Chicago Police Dept. from 2004 to 2016 

## About
We have collected, cleaned, and analyzed data from the Chicago PD regarding the arrests, reported crimes, and TRR incidents that the police department has collected between 2004 and 2016. We initially began this project in the wake of the rise of movements like Black Lives Matter and the many impassioned calls for social justice and police reform by the people of this country.  By looking directly at police reports and demographic data, we took a deep dive into the statistics behind police brutality and systemic racism.

## Contents
- **analysisNotebooks:** contains the jupyter notebooks of all the analyses we have performed on our collected data. The notebooks are numbered 1-6 in terms of when we began authoring them. We recommended reading the notebooks in chronological order for the most comprehensive view and understanding of our analysis
- **demographic-and-geographic-programs:** the .ipynb file contains scraping algorithms that acquire demographic data from Statistical Atlas. The C++ files convert boundary coordinates into a map and calculate demographic data for the beats. This [README](https://www.kaggle.com/robertyu02/cpd-police-beat-demographics)  provides an overview of how the map processing algorithms work.
- **trrCSVs:** contains the raw .csv and .txt files of reported crime information and demographic data taken directly from our sources. This folder also contains the cleaned and modified .csv files we use throughout our analysis.

## Technologies Used
- **Languages:** Python 3.7, C++
- **Data Handling:** NumPy, Pandas (data handling) 
- **Visualization:** seaborn, MatPlotLib (specifically Pylot) 
- **Scraping:** Requests, Beautiful Soup
*All of our analysis notebooks were taken directly from our Kaggle profiles. Hence, some of the data downloading/uploading may look strange, as we initially stored our data directly on our Kaggle accounts (it’s the same data we have uploaded here in trrCSVs).*

## Usage/Viewing
Really all that’s needed is to look in the analysisNotebooks folder and follow the notebooks in sequential order. Code and commentary are in all the notebooks.

## References
- **Raw Crime Data:** [Chicago Data Portal](https://data.cityofchicago.org/Public-Safety/Crimes-2001-to-present-Dashboard/5cd6-ry5g)
- **TRR, Action Responses, Subject, and Complaints Data:** [Invisible Institute Github](https://github.com/invinst/chicago-police-data) (Many thanks to Invisible Institute!)
- **How we derived our definition of “*police brutality*”:** [Dept. of Justice](https://www.justice.gov/crt/law-enforcement-misconduct)
- **Demographic Data:** [Statistical Atlas](https://statisticalatlas.com/county/Illinois/Cook-County/Overview)
- **Chicago Block Group Boundaries:** [SafeGraph, Inc.](https://www.safegraph.com/open-census-data)
- **Chicago Police Beat Boundaries:** [Chicago Data Portal](https://data.cityofchicago.org/Public-Safety/Boundaries-Police-Beats-current-/aerh-rz74)
- **Kaggle Accounts:** [Logan](https://www.kaggle.com/loganchang) & [Robert](https://www.kaggle.com/robertyu02)
