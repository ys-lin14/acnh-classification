# ACNH-Classification

#### Context
I wanted to expand upon my previous project and build models to classify turnip price patterns using generated data.

#### Methods:
- naive bayes
- k nearest neighbours
- 5 fold cross validation

#### Goals:
- generate turnip prices 
- classify turnip selling price patterns

#### Results:
I trained a naive bayes and knn classifier using turnip price data generated with C++ and code from Ash Wolf's GitHub.
The naive bayes and knn classififers resulted in average test accuracies of 0.937 and 0.999 respectively.

#### Other Considerations
Price pattern probabilities were dependent upon the previous pattern and non-uniform which resulted in some data imbalance.
Taking this imbalance into consideration I went with stratified k fold cross validation.

Further investigation can be made into cluster visualization using dimensionality reduction techniques,
other classification models such as logistic regression, the effects of reducing training data has on test 
accuracy along with the minimum amount of data to achieve a certain accuracy.

Furthermore, the knn model can be pickled and used to create an application for pattern classification.

#### References
*Animal Crossing New Horizons* [Game]. (2020). Kyoto: Nintendo.

Maddox Knight. (2020). Maddox Knight's Turnip Mafia (Public Edition). [Data]. Retrieved from https://docs.google.com/spreadsheets/d/1hMmewPJvXw-tmabvccC0nWJdN7zw3aQIQzN3EQ9is6g/edit#gid=370566781

Ash Wolf / Treeki. (2020). AC:NH Turnip Price Calculator. [Code]. Retrieved from https://gist.github.com/Treeki/85be14d297c80c8b3c0a76375743325b
