# Python 入门机器学习

Python 是机器学习中最常用的编程语言之一，因其易于学习、强大的库支持和社区生态系统。

接下来，我将逐步说明如何通过 Python 入门机器学习，并介绍需要的一些常用库。

## 安装 Python 和必要的库

首先，确保你已经安装了 Python，你可以访问Python 官方网站 https://www.python.org/ 下载和安装最新版本。

如果你还不熟悉 Python，可以先学习我们的 Python 教程。

常用机器学习库：

```shell
pip install numpy pandas matplotlib seaborn scikit-learn
```

如果你打算使用深度学习框架，安装如下：

```shell
pip install torch  # 或者
pip install tensorflow
```

在使用 Python 进行机器学习时，整个过程一般遵循以下步骤：

导入必要的库 - 例如，NumPy、Pandas 和 Scikit-learn。

加载和准备数据 - 数据是机器学习的核心。你需要加载数据并进行必要的预处理（例如数据清洗、缺失值填补等）。

选择模型和算法 - 根据任务选择适合的机器学习算法（如线性回归、决策树等）。

训练模型 - 使用训练集数据来训练模型。

评估模型 - 使用测试集评估模型的准确性，并根据评估结果优化模型。

调整模型和超参数 - 根据评估结果调整模型的超参数，进一步优化模型性能。


## 一个简单的机器学习例子：使用 Scikit-learn 做分类

Scikit-learn（简称 Sklearn）是一个开源的机器学习库，建立在 NumPy、SciPy 和 matplotlib 这些科学计算库之上，提供了简单高效的数据挖掘和数据分析工具。

Scikit-learn 包含了许多常见的机器学习算法，包括：

线性回归、岭回归、Lasso回归

支持向量机（SVM）

决策树、随机森林、梯度提升树

聚类算法（如K-Means、层次聚类、DBSCAN）

降维技术（如PCA、t-SNE）

神经网络

接下来我们通过一个简单的分类任务——使用鸢尾花数据集（Iris Dataset）来演示机器学习的流程，鸢尾花数据集是一个经典的数据集，包含 150 个样本，描述了三种不同类型的鸢尾花的花瓣和萼片的长度和宽度。

### 步骤 1：导入库

导入需要的 Python 库：

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
```

### 步骤 2：加载数据

加载鸢尾花数据集：

```python
# 加载鸢尾花数据集
iris = load_iris()

# 将数据转化为 pandas DataFrame
X = pd.DataFrame(iris.data, columns=iris.feature_names)  # 特征数据
y = pd.Series(iris.target)  # 标签数据

# 显示前五行数据
print(X.head())
```

打印输出数据如下所示：

![打印数据](https://github.com/looken1024/algorithm/blob/main/%E6%9C%BA%E5%99%A8%E5%AD%A6%E4%B9%A0/images/infoflow 2025-05-04 20-54-55.png)

### 步骤 3：数据集划分

将数据集划分为训练集和测试集，通常使用 70% 训练集和 30% 测试集的比例：

```python
# 划分训练集和测试集（80% 训练集，20% 测试集）
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
```

### 步骤 4：特征缩放（标准化）

许多机器学习算法都依赖于特征的尺度，特别是像 K 最近邻算法。为了确保每个特征的均值为 0，标准差为 1，我们使用标准化来处理数据：

```python
# 标准化特征
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
```

### 步骤 5：选择模型并训练

在这个例子中，我们选择 K-Nearest Neighbors（KNN） 算法来进行分类：

```python
# 创建 KNN 分类器
knn = KNeighborsClassifier(n_neighbors=3)

# 训练模型
knn.fit(X_train, y_train)
```

### 步骤 6：评估模型

训练完成后，我们使用测试集评估模型的准确性：

```python
# 预测测试集
y_pred = knn.predict(X_test)

# 计算准确率
accuracy = accuracy_score(y_test, y_pred)
print(f'模型准确率: {accuracy:.2f}')
```

完成以上代码，输出结果为：

![评估结果](https://github.com/looken1024/algorithm/blob/main/%E6%9C%BA%E5%99%A8%E5%AD%A6%E4%B9%A0/images/infoflow%202025-05-04%2020-54-55.png)

### 步骤 7：可视化结果（可选）

你可以通过可视化来进一步了解模型的表现，尤其是在多维数据集的情况下。例如，你可以用二维图来显示 KNN 分类的结果（不过在这里需要对数据进行降维，简化为二维）。

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# 加载鸢尾花数据集
iris = load_iris()

# 将数据转化为 pandas DataFrame
X = pd.DataFrame(iris.data, columns=iris.feature_names)  # 特征数据
y = pd.Series(iris.target)  # 标签数据

# 划分训练集和测试集（80% 训练集，20% 测试集）
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 标准化特征
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 创建 KNN 分类器
knn = KNeighborsClassifier(n_neighbors=3)

# 训练模型
knn.fit(X_train, y_train)

# 预测测试集
y_pred = knn.predict(X_test)

# 计算准确率
accuracy = accuracy_score(y_test, y_pred)

# 可视化 - 这里只是一个简单示例，具体可根据实际情况选择绘图方式
plt.scatter(X_test[:, 0], X_test[:, 1], c=y_pred, cmap='viridis', marker='o')
plt.title("KNN Classification Results")
plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.show()
```

输出图片如下所示：

![KNN分类结果](https://github.com/looken1024/algorithm/blob/main/%E6%9C%BA%E5%99%A8%E5%AD%A6%E4%B9%A0/images/knn-python-ml-1.png)

