var app = angular.module("CalculatorApp", []);
app.controller("CalculatorController", function ($scope) {
  $scope.result = function () {
    if ($scope.operator == "+") {
      return $scope.num1 + $scope.num2;
    }
    if ($scope.operator == "-") {
      return $scope.num1 - $scope.num2;
    }
    if ($scope.operator == "*") {
      return $scope.num1 * $scope.num2;
    }
    if ($scope.operator == "/") {
      return $scope.num1 / $scope.num2;
    }
  };
});
