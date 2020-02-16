name := "lms-tutorials"

organization := "org.scala-lang.lms"

scalaVersion := "2.11.2"

scalaOrganization := "org.scala-lang.virtualized"

fork in Test := true;

resolvers += Resolver.sonatypeRepo("snapshots")

libraryDependencies += "org.scala-lang.lms" %% "lms-core" % "1.0.0-SNAPSHOT"

libraryDependencies += "org.scala-lang.virtualized" % "scala-compiler" % "2.11.2"

libraryDependencies += "org.scala-lang.virtualized" % "scala-library" % "2.11.2"

libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "1.1.2"

libraryDependencies += "org.scala-lang.virtualized" % "scala-reflect" % "2.11.2"

libraryDependencies += "org.scalatest" % "scalatest_2.11" % "2.2.2"

libraryDependencies += "com.lihaoyi" %% "pprint" % "0.4.1"

scalacOptions += "-Yvirtualize"

scalacOptions += "-deprecation"

scalacOptions += "-feature"