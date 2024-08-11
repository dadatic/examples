# Dataset

## License

The files under this directory are licensed under the [Creative Commons Attribution 4.0 International](http://creativecommons.org/licenses/by/4.0/legalcode), except where otherwise stated.

## Reference to the original material

Carlos J. Gil Hernandez; Leire Salazar; Jonatan Castaño Muñoz; Irene Pañeda-Fernandez (2023): Teacher's Bias Dataset: A Factorial Survey Experiment. European Commission, Joint Research Centre (JRC) [Dataset] PID: [http://data.europa.eu/89h/f14f5209-f032-4218-a89a-4643143809af](http://data.europa.eu/89h/f14f5209-f032-4218-a89a-4643143809af)

## Contents

* The file `DIGCLASS-BIAS.zip` contains the original material as downloaded from [http://data.europa.eu/89h/f14f5209-f032-4218-a89a-4643143809af](http://data.europa.eu/89h/f14f5209-f032-4218-a89a-4643143809af) on 6 August 2024.
* The file `data.ods` is an OpenDocument Spreadsheet document made of several sheets:
    * The sheet named "Original" contains the original data as imported from the CSV file `data/CSV/cleandataset.csv` from the original material. Except for the chance of import errors or other technical limitations, both sets of data should be the same.
    * The sheet named "Play" contains copies and modifications of the original data for the sake of helping in calculations and testing the effect of some corrections to the original data.
        * Column `sex_female` is a copy of the corresponding column from the sheet named "Original". It represents whether the assessed student is female (value `1`) or male (value `0`).
        * Column `grade_essay` is a copy of the corresponding column from the sheet named "Original". It represents the grades given to the different students.
        * Column `grade_essay_good` is a copy of the corresponding column from the sheet named "Original". It has the same contents as column `grade_essay`, but without the grades for the bad essay.
        * Column `grade_essay_bad` is a copy of the corresponding column from the sheet named "Original". It has the same contents as column `grade_essay`, but without the grades for the good essay.
        * Column `grade_essay_good_female` is new for this project. Contents are generated with a formula that copies contents from column `grade_essay_good` only if the corresponding students are female.
        * Column `grade_essay_good_male` is new for this project. Contents are generated with a formula that copies contents from column `grade_essay_good` only if the corresponding students are male.
        * Column `grade_essay_good_male_comp` is new for this project. Contents are generated with a formula that adds 0.3 to contents from column `grade_essay_good_male`.
        * Column `grade_essay_good_male_comp_lim` is new for this project. Contents are generated with a formula that sets to 10 every value from `grade_essay_good_male_comp` that is greater than 10.
    * The sheet named "Frequencies" contains calculation of frequencies for each grade. It calculates frequencies from the values in sheet "Play".
        * Column `Grade` contains every possible grade with one-tenth precision.
        * Column `Female` contains how many female students have obtained each grade.
        * Column `Male` contains how many male students have obtained each grade.
        * Column `Total` contains how many students have obtained each grade regardless of gender.
        * Column `Male (norm.)` is like column `Male`, but with a correction factor to correct the effect of a bigger male population.
        * Column `Male compensated` contains how many male students would have obtained each grade if 0.3 had been added to their grades without exceeding 10.
        * Column `Total after comp.` contains how many students would have obtained each grade regardless of gender if 0.3 had been added to the grades of male students without exceeding 10.
        * Column `Male compensated (norm.)` is like column `Male compensated`, but with a correction factor to correct the effect of a bigger male population.

