import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

def get_sample_trends(data, pattern_column='pattern', n_trends=10):
    """Get a sample of weekly trends from turnip selling price data
    
    Args:
        data (dataframe): weekly turnip selling price data (wide format)
        pattern_column (str): column containing trend patterns from 0 to 3
        n_trends (int): number of trends per pattern
    
    Returns:
        sample_trends (dataframe):
            sample of (4 * n_trends) weekly selling price trends
    """
    
    sample_trends = [
        data.loc[data[pattern_column] == pattern].sample(n_trends) 
        for pattern in range(0, 4)
    ]

    sample_trends = pd.concat(sample_trends)
    sample_trends.reset_index(drop=True, inplace=True)
    return sample_trends

def plot_trends(data, subset_column, hue, title=None):
    """
    Args:
        data (dataframe): weekly turnip selling price data (long format)
        subset_column (str): column to be used for facets
        hue (str): hue argument for seaborn FacetGrid
        title (str): supertitle for the FacetGrid

    Returns:
        None
    """

    trend_grid = sns.FacetGrid(
        data, 
        col=subset_column, 
        col_wrap=2, 
        aspect=2, 
        sharex=False,
        sharey=False,
        hue=hue
    )
    trend_grid = trend_grid.map(sns.lineplot, 'time', 'price', sort=False)
    trend_grid.set(xlabel='Weekday and Time', ylabel='Selling Price')

    for ax in trend_grid.axes.flat:
        labels = ax.get_xticklabels() # get x labels
        ax.set_xticklabels(labels, rotation=30, ha='right') # set new labels

    plt.suptitle(title)
    plt.subplots_adjust(hspace=1)
    plt.show()
