 mvn clean package -Dmaven.test.skip=true
 mvn surefire:test -Dtest=ml.dmlc.xgboost4j.java.BoosterImplTest
mvn -Dtest=ml.dmlc.xgboost4j.java.BoosterImplTest#testPredictInst+testBoosterBasic test