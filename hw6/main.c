#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Add_Product()
{
  FILE *fp=fopen("products.txt","a+");
  int i=1,j,k=0;
  char type,name_product[9],brand[6],control[100];
  float price;
  // take new product
  printf("Enter product type: ");
  scanf(" %c",&type);

  printf("Enter product name: ");
  scanf("%8s",name_product);


  printf("Enter product brand: ");
  scanf("%5s",brand);

  printf("Enter product price: ");
  scanf("%f",&price);

  strcat(name_product, "\0");
	strcat(brand, "\0");

  while(fscanf(fp,"%s",control) != EOF)   k++;  // count file line

  fprintf(fp,"%d,%c,%s,%s,%.2f\n",k,type,name_product,brand,price);  // write to file
  printf("\nProduct Added\n\n");
  fclose(fp);
}
void Delete_Product()
{
    FILE *fp, *fb;
    int id = 0, pd, control1 = 0, i = 0, k = 0, result;
    char type, name[9], brand[6], control[100];
    float price;

    fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error opening products.txt file!\n\n");
        return;
    }
    fb = fopen("temp.txt", "w");
    if (fb == NULL) {
        printf("Error creating temp.txt file!\n\n");
        fclose(fp);
        return;
    }
    // Count number of lines in file
    while (fgets(control, sizeof(control), fp) != NULL) {
        control1++;
    }
    rewind(fp);
    fgets(control, sizeof(control), fp);
    fprintf(fb,"%s",control);  // read first line product informations

    printf("Enter pID of the product you want to delete: ");
    scanf("%d", &pd);

    // Copy file contents to temp file, except the line with the matching pID
    while (fgets(control, sizeof(control), fp) != NULL) {
        sscanf(control, "%d,%c,%[^,],%[^,],%f", &id, &type, name, brand, &price);
        if (id == pd) {  // if product found work here
            continue;
        } else if (id > pd) {
            id--;  // every pID substrack one
        }
        fprintf(fb, "%d,%c,%s,%s,%.2f\n", id, type, name, brand, price);
    }
    fclose(fp);
    fclose(fb);
    if (remove("products.txt") != 0) {    // remowe file
        printf("Error deleting products.txt file!\n\n");
        return;
    }
    if (rename("temp.txt", "products.txt") != 0) {   // rename temp file to product file
        printf("Error renaming temp.txt file!\n\n");
        return;
    }
    printf("Product Deleted!\n\n");
}
void Update_Product()
{
    FILE *fp, *fb;
    int id, pd, control1 = 0, i = 0, k = 0, result;
    char feature[20], type, name[9], brand[6], control[100];
    float price;
    fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error opening products.txt file!\n\n");
        return;
    }
    fb = fopen("temp.txt", "w");
    if (fb == NULL) {
        printf("Error creating temp.txt file!\n\n");
        fclose(fp);
        return;
    }
    // Count number of lines in file
    while (fgets(control, sizeof(control), fp) != NULL) {
        control1++;
    }
    rewind(fp);
    fgets(control, sizeof(control), fp);
    fprintf(fb,"%s",control);  // read first line informations

    printf("Enter pID of the product you want to update: ");
    scanf("%d", &pd);

    // Update feature of the product with matching pID
    while (fgets(control, sizeof(control), fp) != NULL) {
        sscanf(control, "%d,%c,%[^,],%[^,],%f", &id, &type, name, brand, &price);
        if (id == pd) {
            printf("Enter the name of the feature to update(type,name,brand,price): ");
            scanf("%s", feature);
            if (strcmp(feature, "type") == 0) {
                printf("Enter the new type of the product: ");
                scanf(" %c", &type);
            } else if (strcmp(feature, "name") == 0) {
                printf("Enter the new name of the product: ");
                scanf("%s", name);
            } else if (strcmp(feature, "brand") == 0) {
                printf("Enter the new brand of the product: ");
                scanf("%s", brand);
            } else if (strcmp(feature, "price") == 0) {
                printf("Enter the new price of the product: ");
                scanf("%f", &price);
            } else {
                printf("Invalid feature name!\n\n");
                continue;
            }
        }
        fprintf(fb, "%d,%c,%s,%s,%.2f\n", id, type, name, brand, price);
    }
    fclose(fp);
    fclose(fb);

    if (remove("products.txt") != 0) {
        printf("Error deleting products.txt file!\n\n");
        return;
    }

    if (rename("temp.txt", "products.txt") != 0) {
        printf("Error renaming temp.txt file!\n\n");
        return;
    }
    printf("Product Updated!\n\n");
}
void Add_Feature()
{
    FILE *fp, *fb;
    char feature[50], control[100];
    printf("Enter the name of the new feature: ");
    scanf("%s", feature);
    fp = fopen("products.txt", "a+");
    if (fp == NULL) {
        printf("Error opening products.txt file!\n\n");
        return;
    }
    fb = fopen("temp.txt", "a+");
    if (fb == NULL) {
        printf("Error creating temp.txt file!\n\n");
        fclose(fp);
        return;
    }
    // Copy the first line of the file
    fgets(control, sizeof(control), fp);
    control[strlen(control) - 1] = '\0';
    fprintf(fb, "%s,%s\n", control, feature);
    // Copy the remaining lines of the file
    while (fgets(control, sizeof(control), fp) != NULL)
    {
        // Add ",None" to the end of each line
        control[strlen(control) - 1] = '\0';
        strcat(control, ",None\n");
        fprintf(fb, "%s", control);
    }
    fclose(fp);
    fclose(fb);
    if (remove("products.txt") != 0) {
        printf("Error deleting products.txt file!\n\n");
        return;
    }
    if (rename("temp.txt", "products.txt") != 0) {
        printf("Error renaming temp.txt file!\n\n");
        return;
    }
    printf("Feature added!\n\n");
}
void Add_Stock()
{
  FILE *fp=fopen("stocks.txt","a+");
  int i=1,j,k=0,pID;
  char branch[16],control[100];

  printf("Enter product's pID: ");
  scanf(" %d",&pID);

  printf("Enter branch name: ");
  scanf("%15s",branch);

  printf("Enter current stock: ");
  scanf("%d",&j);

	strcat(branch, "\0");

  while(fscanf(fp,"%s",control) != EOF)   k++;

  fprintf(fp,"%d,%d,%s,%d\n",k,pID,branch,j);
  printf("\nNew stock added\n\n");
  fclose(fp);
}
void Delete_Stock()
{
    FILE *fp, *fb;
    int sd = 0, id, p_id, control1 = 0, i = 0, k = 0, result;
    char branch[20], control[100];
    int current_stock;
    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening stocks.txt file!\n\n");
        return;
    }
    fb = fopen("temp.txt", "w");
    if (fb == NULL) {
        printf("Error creating temp.txt file!\n\n");
        fclose(fp);
        return;
    }
    // Count number of lines in file
    while (fgets(control, sizeof(control), fp) != NULL) {
        control1++;
    }
    rewind(fp);
    fgets(control, sizeof(control), fp);
    fprintf(fb,"%s",control); // read first line

    printf("Enter sID of the stock entry you want to delete: ");
    scanf("%d", &sd);
    // Copy file contents to temp file, except the line with the matching sID
    while (fgets(control, sizeof(control), fp) != NULL) {
        sscanf(control, "%d,%d,%[^,],%d", &id, &p_id, branch, &current_stock);
        if (id == sd) {
            continue;
        } else if (id > sd) {
            id--;
        }
        fprintf(fb, "%d,%d,%s,%d\n", id, p_id, branch, current_stock);
    }
    fclose(fp);
    fclose(fb);
    if (remove("stocks.txt") != 0) {
        printf("Error deleting stocks.txt file!\n\n");
        return;
    }
    if (rename("temp.txt", "stocks.txt") != 0) {
        printf("Error renaming temp.txt file!\n\n");
        return;
    }
    printf("Stock Entry Deleted!\n\n");
}
void Update_Stock()
{
    FILE *fp, *fb;
    int id,sID,sd,control1 = 0,i = 0,k = 0,result;
    char feature[20], branch[20], control[100];
    int current_stock;
    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening stock.txt file!\n\n");
        return;
    }
    fb = fopen("temp.txt", "w");
    if (fb == NULL) {
        printf("Error creating temp.txt file!\n\n");
        fclose(fp);
        return;
    }
    // Count number of lines in file
    while (fgets(control, sizeof(control), fp) != NULL) {
        control1++;
    }
    rewind(fp);
    fgets(control, sizeof(control), fp);
    fprintf(fb,"%s",control);

    printf("Enter sID of the stock entry you want to update: ");
    scanf("%d", &sd);
    // Update feature of the stock entry with matching sID
    while (fgets(control, sizeof(control), fp) != NULL) {
        sscanf(control, "%d,%d,%[^,],%d", &sID, &id, branch, &current_stock);
        if (sd == sID) {
            printf("Enter the name of the feature to update(branch,current_stock,pID):");
            scanf("%s", feature);
            if (strcmp(feature, "branch") == 0) {
                printf("Enter the new branch of the stock entry: ");
                scanf("%s", branch);
            }
            else if (strcmp(feature, "current_stock") == 0) {
                printf("Enter the new value of the current stock: ");
                scanf("%d", &current_stock);
            }
            else if(strcmp(feature, "pID") == 0) {
                printf("Enter the new value of pID: ");
                scanf("%d", &id);
            }
            else {
                printf("Invalid feature name!\n\n");
                continue;
            }
        }
        fprintf(fb, "%d,%d,%s,%d\n", sID, id, branch, current_stock);
    }
    fclose(fp);
    fclose(fb);
    if (remove("stocks.txt") != 0) {
        printf("Error deleting stock.txt file!\n\n");
        return;
    }
    if (rename("temp.txt", "stocks.txt") != 0) {
        printf("Error renaming temp.txt file!\n\n");
        return;
    }
    printf("\nStock Updated!\n\n");
}
void File_Operations()
{
  int choose=0;
  while(1)
  {
    printf("1. Add a new product\n2. Delete a product\n3. Update a product\n4. Add feature to products\n");
    printf("5. Add a new stock entry\n6. Delete a stock entry\n7. Update a stock entry\n8. Back to main menu\n");
    scanf("%d",&choose);
    switch(choose){
      case 1: Add_Product(); break;
      case 2: Delete_Product(); break;
      case 3: Update_Product(); break;
      case 4: Add_Feature(); break;
      case 5: Add_Stock(); break;
      case 6: Delete_Stock(); break;
      case 7: Update_Stock(); break;
      case 8: return;
    }
  }
}
void listAllProducts()   // list all products  here
{
    FILE* fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error opening products.txt file!\n\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
    printf("\n");
}
void filterProducts()
{
    char filter_type[20];
    printf("Enter filter type (brand, type, price, feature): ");
    scanf("%s", filter_type);

    char filter_values[100];
    printf("Enter filter value/s (for example: brand,Sutas): ");
    scanf("%s", filter_values);

    char brand_filter[50] = "";
    char type_filter[2] = "";
    double min_price = 0.0;
    double max_price = 0.0;
    int use_price_filter = 0;

    char *token = strtok(filter_values, ",");
    while (token != NULL) {
      if (strcmp(token, "brand") == 0) {
          token = strtok(NULL, ",");
          if (token != NULL) {
              strcpy(brand_filter, token);
          } else {
              printf("Invalid filter values: brand filter requires a value.\n");
              return;
          }
      } else if (strcmp(token, "type") == 0) {
          token = strtok(NULL, ",");
          if (token != NULL) {
              strcpy(type_filter, token);
          } else {
              printf("Invalid filter values: type filter requires a value.\n");
              return;
          }
      } else if (strcmp(token, "price") == 0) {
          use_price_filter = 1;
          printf("Enter minimum price: ");
          scanf("%lf", &min_price);
          printf("Enter maximum price: ");
          scanf("%lf", &max_price);
      } else {
          printf("Invalid filter type: %s\n", token);
          return;
      }
      token = strtok(NULL, ",");
  }

    FILE *fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return;
    }

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        int pID;
        char type[2];
        char name[50];
        char brand[50];
        double price;

        sscanf(line, "%d,%[^,],%[^,],%[^,],%lf", &pID, type, name, brand, &price);

        int match = 1;
        if (strlen(brand_filter) > 0 && strcmp(brand_filter, brand) != 0) {
            match = 0;
        }
        if (strlen(type_filter) > 0 && strcmp(type_filter, type) != 0) {
            match = 0;
        }
        if (use_price_filter && (price < min_price || price > max_price)) {
            match = 0;
        }
        if (match) {
            printf("%s", line);
        }
    }
    fclose(fp);
    printf("\n");
}
void Query_Products()
{
  int a;
  while(1)
  {
    printf("1. List all products\n2. Filter products by brand, type, price, or a user-defined feature\n3. Back to main menu.\n");
    scanf("%d",&a);
    switch(a){
      case 1: listAllProducts(); break;
      case 2: filterProducts();  break;
      case 3: return;
    }
  }
}
void filterByProductAndBranch()  // here filtered according to branch and product name
{
    int pID;
    char branch[50];

    printf("Enter product ID: ");
    scanf("%d", &pID);

    printf("Enter branch name: ");
    scanf("%s", branch);

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return;
    }
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        int sID;
        int pID_in_file;
        char branch_in_file[50];
        int stock;

        sscanf(line, "%d,%d,%[^,],%d", &sID, &pID_in_file, branch_in_file, &stock);

        if (pID_in_file == pID && strcmp(branch, branch_in_file) == 0) {
            printf("%s", line);
        }
    }

    fclose(fp);
    printf("\n");
}
void filterByBranch()  // here filtered according to branch name
{
    char branch[50];
    printf("Enter branch name: ");
    scanf("%s", branch);

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return;
    }
    char line[100];
    while (fgets(line, 100, fp) != NULL) {  // here found true branch
        int sID;
        int pID;
        char branch_in_file[50];
        int stock;

        sscanf(line, "%d,%d,%[^,],%d", &sID, &pID, branch_in_file, &stock);

        if (strcmp(branch, branch_in_file) == 0) {
            printf("%s", line);  // printed true branch
        }
    }
    fclose(fp);
    printf("\n");
}
void filterOutOfStock()   // filtered out of stocks
{
    char branch[50];
    printf("Enter branch name: ");
    scanf("%s", branch);

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return;
    }
    char line[100];
    while (fgets(line, 100, fp) != NULL) {   // here found 0 stocks
        int sID, pID;
        char branch_in_file[50];
        int stock;

        sscanf(line, "%d,%d,%[^,],%d", &sID, &pID, branch_in_file, &stock);

        if (strcmp(branch, branch_in_file) == 0 && stock == 0) {
            printf("%d,%d,%s,%d\n", sID, pID, branch_in_file, stock);
        }
    }
    fclose(fp);
    printf("\n");
}
void Check_Stock_Status()  // part 4
{
  int a;
  while(1)
  {
    printf("1-Filter Product And Branch\n2-Filter Stock with Branch\n3-Out of stock Products\n4-Back to menu\n");
    scanf("%d",&a);
    switch(a){
      case 1: filterByProductAndBranch();  break;
      case 2: filterByBranch();  break;
      case 3: filterOutOfStock(); break;
      case 4: return;
    }
  }
}
void Brand_control() {
    char brand[20];
    printf("Enter brand name: ");
    scanf("%s", brand);

    FILE *fp_products = fopen("products.txt", "r");
    FILE *fp_stocks = fopen("stocks.txt", "r");

    if (fp_products == NULL || fp_stocks == NULL) {
        printf("Error opening file \n");
        return;
    }
    int count = 0;
    // Find the number of products for the given brand
    char line[100];
    while (fgets(line, 100, fp_products) != NULL) {
        int pID;
        char type[20];
        char name[50];
        char brand_in_file[20];
        double price;

        sscanf(line, "%d,%[^,],%[^,],%[^,],%lf", &pID, type, name, brand_in_file, &price);

        if (strcmp(brand, brand_in_file) == 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("No products found for given brand.\n");
    } else {
        // Create a 2D array to store the product details
        double brand_products[count][3];
        rewind(fp_products);
        int i = 0;
        while (fgets(line, 100, fp_products) != NULL) {
            int pID;
            char type[20];
            char name[50];
            char brand_in_file[20];
            double price;
            sscanf(line, "%d,%[^,],%[^,],%[^,],%lf", &pID, type, name, brand_in_file, &price);
            if (strcmp(brand, brand_in_file) == 0) {
                brand_products[i][0] = pID;
                brand_products[i][1] = price;
                i++;
            }
        }
        // Add the current stock to the 2D array
        while (fgets(line, 100, fp_stocks) != NULL) {
            int sID, pID;
            char branch[50];
            double current_stock;

            sscanf(line, "%d,%d,%[^,],%lf", &sID, &pID, branch, &current_stock);

            for (int j = 0; j < count; j++) {
                if (brand_products[j][0] == pID) {
                    brand_products[j][2] = current_stock;
                }
            }
        }
        // Print the product details for the given brand
        printf("Products of brand %s:\n", brand);
        printf("pID\tPrice\tCurrent Stock\n");

        for (int j = 0; j < count; j++) {
            printf("%.0lf\t%.2lf\t%.2lf\n", brand_products[j][0], brand_products[j][1], brand_products[j][2]);
        }
    }
    fclose(fp_products);
    fclose(fp_stocks);
    printf("\n");
}
void generateReport()
{
    FILE *fp_products = fopen("products.txt", "r");
    FILE *fp_stocks = fopen("stocks.txt", "r");
    FILE *fp_report = fopen("report.txt", "w");

    if (fp_products == NULL || fp_stocks == NULL || fp_report == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read products into an array
    char line[100];
    int count = 0;

    while (fgets(line, 100, fp_products) != NULL) {
        int pID;
        char type[20];
        char name[50];
        char brand[20];
        double price;

        sscanf(line, "%d,%[^,],%[^,],%[^,],%lf", &pID, type, name, brand, &price);

        count++;
    }
    double products[count][3];
    int i = 0;

    rewind(fp_products);
    fgets(line, 100, fp_products);

    while (fgets(line, 100, fp_products) != NULL) {
        int pID;
        char type[20];
        char name[50];
        char brand[20];
        double price;

        sscanf(line, "%d,%[^,],%[^,],%[^,],%lf", &pID, type, name, brand, &price);

        products[i][0] = pID;
        i++;
    }

    // Read stocks into an array
    double stocks[count][100];
    int j = 0;
    fgets(line, 100, fp_stocks);
    while (fgets(line, 100, fp_stocks) != NULL) {
        int sID, pID;
        char branch[50];
        double current_stock;

        sscanf(line, "%d,%d,%[^,],%lf", &sID, &pID, branch, &current_stock);

        for (int k = 0; k < count; k++) {
            if (products[k][0] == pID) {
                stocks[k][j] = current_stock;
                j++;
                break;
            }
        }
    }
    // Calculate min, max, and median of stocks for each product
    fprintf(fp_report, "pID,Min Stock,Max Stock,Median Stock\n");

    for (int k = 0; k < count-1; k++) {
        double min = stocks[k][0];
        double max = stocks[k][0];
        double sum = 0;

        for (int l = 0; l < j; l++) {
            if (stocks[k][l] < min) {
                min = stocks[k][l];
            }
            if (stocks[k][l] > max) {
                max = stocks[k][l];
            }
            sum += stocks[k][l];
        }

        double median = 0;
        if (j % 2 == 0) {
            median = (stocks[k][j / 2 - 1] + stocks[k][j / 2]) / 2;
        } else {
            median = stocks[k][j / 2];
        }

        fprintf(fp_report, "%.0lf,%.2lf,%.2lf,%.2lf\n", products[k][0], min, max, median);
    }
    printf("\nReported\n\n");
    fclose(fp_products);
    fclose(fp_stocks);
    fclose(fp_report);
}

void part_one()
{
  int choose=-1;
  while(choose != 0)
  {
    printf("1-File Operations\n2-Query products\n3-Check stock status\n4-Stock control by brand\n5-Export report\n0-Exit\n");
    scanf("%d",&choose);
    switch(choose){
      case 0: return;
      case 1: File_Operations(); break;
      case 2: Query_Products(); break;
      case 3: Check_Stock_Status(); break;
      case 4: Brand_control(); break;
      case 5: generateReport(); break;
    }
  }
}

int main()
{
  FILE *fp=fopen("products.txt","a+"),*fb=fopen("stocks.txt","a+");
  fprintf(fp,"pID,Type,Name,Brand,Price\n");
  fprintf(fb,"sID,pID,branch,current_stock\n");
  fclose(fp);  fclose(fb);
  part_one();
  //remove("stocks.txt");  remove("products.txt");

}
