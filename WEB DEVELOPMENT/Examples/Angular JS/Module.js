var myApp = angular.module("myApp", []);

// myApp.config(function () {});

// myApp.run(function () {});

myApp.controller("AppController", [
  "$scope",
  function ($scope) {
    $scope.message = "Hello from js";

    $scope.names = ["Arun", "Kishore", "Kumar", "Siva"];
  },
]);
