; ModuleID = 'test.cpp'
source_filename = "test.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@__const.main.numandnum = private unnamed_addr constant [257 x i8] c"109000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000+999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999\00", align 16
@.str = private unnamed_addr constant [22 x i8] c"\E7\AC\AC\E4\B8\80\E4\B8\AA\E6\95\B4\E6\95\B0\EF\BC\9A %s\00", align 1
@.str.1 = private unnamed_addr constant [22 x i8] c"\E7\AC\AC\E4\BA\8C\E4\B8\AA\E6\95\B4\E6\95\B0\EF\BC\9A %s\00", align 1

; Function Attrs: mustprogress noinline norecurse optnone uwtable
define dso_local noundef i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [257 x i8], align 16
  %3 = alloca [256 x i8], align 16
  %4 = alloca [256 x i8], align 16
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  call void @llvm.memcpy.p0.p0.i64(ptr align 16 %2, ptr align 16 @__const.main.numandnum, i64 257, i1 false)
  store i32 0, ptr %5, align 4
  br label %7

7:                                                ; preds = %15, %0
  %8 = load i32, ptr %5, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [257 x i8], ptr %2, i64 0, i64 %9
  %11 = load i8, ptr %10, align 1
  %12 = sext i8 %11 to i32
  %13 = icmp ne i32 %12, 43
  br i1 %13, label %14, label %18

14:                                               ; preds = %7
  br label %15

15:                                               ; preds = %14
  %16 = load i32, ptr %5, align 4
  %17 = add nsw i32 %16, 1
  store i32 %17, ptr %5, align 4
  br label %7, !llvm.loop !6

18:                                               ; preds = %7
  %19 = getelementptr inbounds [256 x i8], ptr %3, i64 0, i64 0
  %20 = getelementptr inbounds [257 x i8], ptr %2, i64 0, i64 0
  %21 = load i32, ptr %5, align 4
  %22 = sext i32 %21 to i64
  %23 = call ptr @strncpy(ptr noundef %19, ptr noundef %20, i64 noundef %22) #5
  %24 = load i32, ptr %5, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [256 x i8], ptr %3, i64 0, i64 %25
  store i8 0, ptr %26, align 1
  %27 = getelementptr inbounds [256 x i8], ptr %4, i64 0, i64 0
  %28 = getelementptr inbounds [257 x i8], ptr %2, i64 0, i64 0
  %29 = load i32, ptr %5, align 4
  %30 = sext i32 %29 to i64
  %31 = getelementptr inbounds i8, ptr %28, i64 %30
  %32 = getelementptr inbounds i8, ptr %31, i64 1
  %33 = getelementptr inbounds [257 x i8], ptr %2, i64 0, i64 0
  %34 = call i64 @strlen(ptr noundef %33) #6
  %35 = load i32, ptr %5, align 4
  %36 = sext i32 %35 to i64
  %37 = sub i64 %34, %36
  %38 = sub i64 %37, 1
  %39 = call ptr @strncpy(ptr noundef %27, ptr noundef %32, i64 noundef %38) #5
  %40 = getelementptr inbounds [257 x i8], ptr %2, i64 0, i64 0
  %41 = call i64 @strlen(ptr noundef %40) #6
  %42 = load i32, ptr %5, align 4
  %43 = sext i32 %42 to i64
  %44 = sub i64 %41, %43
  %45 = sub i64 %44, 1
  %46 = getelementptr inbounds [256 x i8], ptr %4, i64 0, i64 %45
  store i8 0, ptr %46, align 1
  %47 = getelementptr inbounds [256 x i8], ptr %3, i64 0, i64 0
  %48 = call i32 (ptr, ...) @printf(ptr noundef @.str, ptr noundef %47)
  %49 = getelementptr inbounds [256 x i8], ptr %4, i64 0, i64 0
  %50 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, ptr noundef %49)
  ret i32 0
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #1

; Function Attrs: nounwind
declare ptr @strncpy(ptr noundef, ptr noundef, i64 noundef) #2

; Function Attrs: nounwind willreturn memory(read)
declare i64 @strlen(ptr noundef) #3

declare i32 @printf(ptr noundef, ...) #4

attributes #0 = { mustprogress noinline norecurse optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nounwind willreturn memory(argmem: readwrite) }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind willreturn memory(read) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nounwind }
attributes #6 = { nounwind willreturn memory(read) }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
